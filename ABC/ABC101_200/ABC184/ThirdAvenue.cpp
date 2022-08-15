#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll H, W;

ll bfs(const vector<string> &grid) {

    pair<ll, ll> start;
    pair<ll, ll> goal;
    map<char, pair<bool, vector<pair<ll, ll>>>> telepo;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(grid.at(i).at(j) == 'S') {
                start = {i, j};
            } else if(grid.at(i).at(j) == 'G') {
                goal = {i, j};
            } else if(grid.at(i).at(j) >= 'a' and grid.at(i).at(j) <= 'z') {
                telepo[grid.at(i).at(j)].first = true;
                telepo[grid.at(i).at(j)].second.push_back({i, j});
            }
        }
    }

    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    // BFS のためのデータ構造
    vector<vector<ll>> dist(grid.size(), vector<ll>(grid.at(0).length(), -1)); // 全頂点を「未訪問」に初期化
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
            if(v.second + d.second >= (ll) grid.at(0).length()) {
                continue;
            }
            if (grid[v.first + d.first][v.second + d.second] == '#') continue; // 壁は探索しない
            if (dist[v.first + d.first][v.second + d.second] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[v.first + d.first][v.second + d.second] = dist[v.first][v.second] + 1;
            que.push({v.first + d.first, v.second + d.second});
        }
        if(telepo.count(grid.at(v.first).at(v.second)) == 1 && telepo[grid.at(v.first).at(v.second)].first) {
            for(pair<ll, ll> t : telepo[grid.at(v.first).at(v.second)].second) {
                if(t.first == v.first && t.second == v.second) {
                    continue;
                }
                if (dist[t.first][t.second] != -1) continue; // すでに発見済みの頂点は探索しない
                // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                dist[t.first][t.second] = dist[v.first][v.second] + 1;
                que.push({t.first, t.second});
            }
            telepo[grid.at(v.first).at(v.second)].first = false;
        }
    }

    return dist.at(goal.first).at(goal.second);
}

int main() {
    cin >> H >> W;
    vector<string> s(H);
    for(string &elm : s) {
        cin >> elm;
    }

    ll ans = bfs(s);

    cout << ans << endl;
    return 0;
}