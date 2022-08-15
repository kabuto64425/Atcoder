#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

struct Route {
    ll r, c, direction;
};

bool can_move(Route v, pair<ll, ll> d, const vector<vector<ll>> &grid) {
    if(v.r + d.first < 0) {
        return false;
    }
    if(v.r + d.first >= (ll) grid.size()) {
        return false;
    }
    if(v.c + d.second < 0) {
        return false;
    }
    if(v.c + d.second >= (ll) grid.at(0).size()) {
        return false;
    }
    if (grid[v.r + d.first][v.c + d.second] == 1) {
        return false;// 壁は探索しない
    }

    return true;
}

vector<vector<vector<ll>>> bfs(const vector<vector<ll>> &grid, pair<ll, ll> start) {

    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    // BFS のためのデータ構造
    vector<vector<vector<ll>>> dist(grid.size(), vector<vector<ll>>(grid.at(0).size(), vector<ll>(4, INF))); // 全頂点を「未訪問」に初期化
    deque<Route> quePoint;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[start.first][start.second][0] = 0;
    dist[start.first][start.second][1] = 0;
    dist[start.first][start.second][2] = 0;
    dist[start.first][start.second][3] = 0;
    quePoint.push_front({start.first, start.second, 0});
    quePoint.push_front({start.first, start.second, 1});
    quePoint.push_front({start.first, start.second, 2});
    quePoint.push_front({start.first, start.second, 3});

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!quePoint.empty()) {
        Route v = quePoint.front(); // キューから先頭頂点を取り出す
        quePoint.pop_front();

        // 同一の向きに1マス進む
        pair<ll, ll> d = ds.at(v.direction);
        if(can_move(v, d, grid)) {
            if(dist[v.r + d.first][v.c + d.second][v.direction] > dist[v.r][v.c][v.direction]) {
                dist[v.r + d.first][v.c + d.second][v.direction] = dist[v.r][v.c][v.direction];
                quePoint.push_front({v.r + d.first, v.c + d.second, v.direction});
            }
        }
        
        // 方向変換をする
        for(ll i = 1; i <= 3; i++) {
            ll direction = (v.direction + i) % 4;
            if(dist[v.r][v.c][direction] > dist[v.r][v.c][v.direction] + 1) {
                dist[v.r][v.c][direction] = dist[v.r][v.c][v.direction] + 1;
                quePoint.push_back({v.r, v.c, direction});
            }
        }
    }

    return dist;
}

int main() {
    ll H, W;
    cin >> H >> W;

    pair<ll, ll> start;
    cin >> start.first >> start.second;
    start.first--;
    start.second--;

    pair<ll, ll> goal;
    cin >> goal.first >> goal.second;
    goal.first--;
    goal.second--;

    vector<string> S(H);
    REP(i, H) {
        cin >> S.at(i);
    }
    
    vector<vector<ll>> grid(H, vector<ll>(W, 0));
    REP(i, H) {
        REP(j, W) {
            if(S.at(i).at(j) == '#') {
                grid.at(i).at(j) = 1;
            }
        }
    }

    vector<vector<vector<ll>>> dist = bfs(grid, start);

    cout << min({dist[goal.first][goal.second][0], dist[goal.first][goal.second][1], dist[goal.first][goal.second][2], dist[goal.first][goal.second][3]}) << endl;
    return 0;
}