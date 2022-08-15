#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

struct Route {
    ll r, c, direction;
};

bool can_move(Route v, pair<ll, ll> d, ll N, const vector<string> &S) {
    if(v.r + d.first < 0) {
        return false;
    }
    if(v.r + d.first >= N) {
        return false;
    }
    if(v.c + d.second < 0) {
        return false;
    }
    if(v.c + d.second >= N) {
        return false;
    }
    if (S[v.r + d.first][v.c + d.second] == '#') {
        return false;// 壁は探索しない
    }

    return true;
}

void bfs(const vector<string> &S, const ll N, vector<vector<vector<ll>>> &dist, pair<ll, ll> start) {

    const vector<pair<ll, ll>> ds = {
        {1, 1},
        {1, -1},
        {-1, -1},
        {-1, 1},
    };

    // BFS のためのデータ構造
    deque<Route> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[start.first][start.second][0] = 0;
    dist[start.first][start.second][1] = 0;
    dist[start.first][start.second][2] = 0;
    dist[start.first][start.second][3] = 0;
    que.push_front({start.first, start.second, 0});
    que.push_front({start.first, start.second, 1});
    que.push_front({start.first, start.second, 2});
    que.push_front({start.first, start.second, 3});

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        Route v = que.front(); // キューから先頭頂点を取り出す
        que.pop_front();

        // 同一の向きに1マス進む
        pair<ll, ll> d = ds.at(v.direction);
        if(can_move(v, d, N, S)) {
            if(dist[v.r + d.first][v.c + d.second][v.direction] > dist[v.r][v.c][v.direction]) {
                dist[v.r + d.first][v.c + d.second][v.direction] = dist[v.r][v.c][v.direction];
                que.push_front({v.r + d.first, v.c + d.second, v.direction});
            }
        }

        // 方向変換をする
        for(ll i = 1; i <= 3; i++) {
            ll direction = (v.direction + i) % 4;
            if(dist[v.r][v.c][direction] > dist[v.r][v.c][v.direction] + 1) {
                dist[v.r][v.c][direction] = dist[v.r][v.c][v.direction] + 1;
                que.push_back({v.r, v.c, direction});
            }
        }
    }

    return;
}

int main() {
    ll N;
    cin >> N;
    ll Ax, Ay;
    cin >> Ax >> Ay;
    ll Bx, By;
    cin >> Bx >> By;
    vector<string> S(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i);
    }

    vector<vector<vector<ll>>> dist(N, vector<vector<ll>>(N, vector<ll>(4, INF))); // 全頂点を「未訪問」に初期化
    //vector<vector<ll>> dist(N, vector<ll>(N, -1)); // 全頂点を「未訪問」に初期化

    bfs(S, N, dist, {Ax - 1, Ay - 1});

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    ll ans = INF;
    for(ll i = 0; i < 4; i++) {
        ans = min(ans, dist[Bx - 1][By - 1][i]);
    }
    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans + 1 << endl;
    return 0;
}