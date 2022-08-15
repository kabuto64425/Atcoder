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

bool can_move(pair<ll, ll> v, pair<ll, ll> d, const vector<vector<ll>> &grid) {
    if(v.first + d.first < 0) {
        return false;
    }
    if(v.first + d.first >= (ll) grid.size()) {
        return false;
    }
    if(v.second + d.second < 0) {
        return false;
    }
    if(v.second + d.second >= (ll) grid.at(0).size()) {
        return false;
    }
    if (grid[v.first + d.first][v.second + d.second] == 1) {
        return false;// 壁は探索しない
    }

    return true;
}

void bfs(const vector<vector<ll>> &grid, pair<ll, ll> start, vector<vector<ll>> &dist) {
    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };
    deque<pair<ll, ll>> quePoint;
    dist[start.first][start.second] = 0;
    quePoint.push_front({start.first, start.second});

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!quePoint.empty()) {
        pair<ll, ll> v = quePoint.front(); // キューから先頭頂点を取り出す
        quePoint.pop_front();
        
        for(pair<ll, ll> d : ds) {
            if(can_move(v, d, grid)) {
                if(dist[v.first + d.first][v.second + d.second] > dist[v.first][v.second]) {
                    dist[v.first + d.first][v.second + d.second] = dist[v.first][v.second];
                    quePoint.push_front({v.first + d.first, v.second + d.second});
                }
            }
        }

        for(ll i = -2; i <= 2; i++) {
            for(ll j = -2; j <= 2; j++) {
                if(i == -2 and j == -2) {
                    continue;
                }
                if(i == -2 and j == 2) {
                    continue;
                }
                if(i == 2 and j == -2) {
                    continue;
                }
                if(i == 2 and j == 2) {
                    continue;
                }

                if(v.first + i < 0) {
                    continue;
                }
                if(v.first + i >= (ll) grid.size()) {
                    continue;
                }
                if(v.second + j < 0) {
                    continue;
                }
                if(v.second + j >= (ll) grid.at(0).size()) {
                    continue;
                }

                if(dist[v.first + i][v.second + j] > dist[v.first][v.second] + 1) {
                    dist[v.first + i][v.second + j] = dist[v.first][v.second] + 1;
                    quePoint.push_back({v.first + i, v.second + j});
                }
            }
        }
    }
    return;
}

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(ll i = 0; i < H; i++) {
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

    // BFS のためのデータ構造
    vector<vector<ll>> dist(H, vector<ll>(W, INF)); // 全頂点を「未訪問」に初期化

    bfs(grid, {0, 0}, dist);
    cout << dist[H - 1][W - 1] << endl;
    return 0;
}