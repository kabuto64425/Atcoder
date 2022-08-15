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

vector<vector<ll>> bfs(const vector<vector<ll>> &grid, pair<ll, ll> start) {

    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    // BFS のためのデータ構造
    vector<vector<ll>> dist(grid.size(), vector<ll>(grid.at(0).size(), INF)); // 全頂点を「未訪問」に初期化
    deque<pair<ll, ll>> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[start.first][start.second] = 0;
    que.push_front(start); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        pair<ll, ll> v = que.front(); // キューから先頭頂点を取り出す
        que.pop_front();

        // v から辿れる頂点をすべて調べる
        for (pair<ll, ll> d : ds) {
            if(v.first + d.first < 0) {
                continue;
            }
            if(v.first + d.first >= (ll) grid.size()) {
                continue;
            }
            if(v.second + d.second < 0) {
                continue;
            }
            if(v.second + d.second >= (ll) grid.at(0).size()) {
                continue;
            }
            if (grid[v.first + d.first][v.second + d.second] == 1) continue; // 壁は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            if(dist[v.first + d.first][v.second + d.second] > dist[v.first][v.second]) {
                dist[v.first + d.first][v.second + d.second] = dist[v.first][v.second];
                que.push_front({v.first + d.first, v.second + d.second});
            }
        }

        for(ll i = -2; i <= 2; i++) {
            for(ll j = - 2; j <= 2; j++) {
                pair<ll, ll> d = {i, j};
                if(v.first + d.first < 0) {
                    continue;
                }
                if(v.first + d.first >= (ll) grid.size()) {
                    continue;
                }
                if(v.second + d.second < 0) {
                    continue;
                }
                if(v.second + d.second >= (ll) grid.at(0).size()) {
                    continue;
                }
                if (grid[v.first + d.first][v.second + d.second] == 1) continue; // 壁は探索しない

                if(dist[v.first + d.first][v.second + d.second] > dist[v.first][v.second] + 1) {
                    dist[v.first + d.first][v.second + d.second] = dist[v.first][v.second] + 1;
                    que.push_back({v.first + d.first, v.second + d.second});
                }
            }
        }
    }

    return dist;
}

int main() {
    ll H, W;
    cin >> H >> W;
    ll Ch, Cw;
    cin >> Ch >> Cw;
    ll Dh, Dw;
    cin >> Dh >> Dw;

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

    vector<vector<ll>> dist = bfs(grid, {Ch - 1, Cw - 1});

    if(dist[Dh - 1][Dw - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }

    cout << dist[Dh - 1][Dw - 1] << endl;
    return 0;
}