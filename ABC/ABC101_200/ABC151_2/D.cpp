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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

void bfs(const vector<string> &S, vector<vector<ll>> &dist, pair<ll, ll> start) {

    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    // BFS のためのデータ構造
    queue<pair<ll, ll>> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[start.first][start.second] = 0;
    que.push(start); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        pair<ll, ll> v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (pair<ll, ll> d : ds) {
            if(v.first + d.first < 0) {
                continue;
            }
            if(v.first + d.first >= (ll) S.size()) {
                continue;
            }
            if(v.second + d.second < 0) {
                continue;
            }
            if(v.second + d.second >= (ll) S.at(0).length()) {
                continue;
            }
            if(S.at(v.first + d.first).at(v.second + d.second) == '#') continue; // 壁は探索しない
            if (dist[v.first + d.first][v.second + d.second] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[v.first + d.first][v.second + d.second] = dist[v.first][v.second] + 1;
            que.push({v.first + d.first, v.second + d.second});
        }
    }

    return;
}

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(ll i = 0; i < H; i++) {
        cin >> S.at(i);
    }

    ll ans = 0;

    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) {
        if(S.at(i).at(j) == '#') {
            continue;
        }
        vector<vector<ll>> dist(S.size(), vector<ll>(S.at(0).length(), -1)); // 全頂点を「未訪問」に初期化
        bfs(S, dist, {i, j});
        for(ll k = 0; k < H; k++) for(ll l = 0; l < W; l++) {
            chmax(ans, dist[k][l]);
        }
    }

    cout << ans << endl;
    return 0;
}