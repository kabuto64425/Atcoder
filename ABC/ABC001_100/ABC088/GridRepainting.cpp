#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

vector<vector<ll>> bfs(const vector<vector<ll>> &grid, pair<ll, ll> start) {

    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    // BFS のためのデータ構造
    vector<vector<ll>> dist(grid.size(), vector<ll>(grid.at(0).size(), -1)); // 全頂点を「未訪問」に初期化
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
            if (dist[v.first + d.first][v.second + d.second] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[v.first + d.first][v.second + d.second] = dist[v.first][v.second] + 1;
            que.push({v.first + d.first, v.second + d.second});
        }
    }

    return dist;
}

signed main() {
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);

    vector<vector<ll>> grid(H, vector<ll>(W, 0));
    ll blockCount = 0;

    REP(i, H) {
        cin >> s.at(i);
        REP(j, W) {
            if(s.at(i).at(j) == '#') {
                grid.at(i).at(j) = 1;
                blockCount++;
            }
        }
    }

    vector<vector<ll>> dist = bfs(grid, {0, 0});

    if(dist[H - 1][W - 1] == -1) {
        cout << -1 << endl;
    } else {
        vector<ll> bucket(H * W, 0);
        cout << H * W - dist[H - 1][W - 1] - blockCount - 1 << endl;
    }
    return 0;
}