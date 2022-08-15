#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法
using Graph = vector<vector<ll>>;

void bfs(vector<vector<ll>> &field, pair<ll, ll> start, ll id) {

    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    // BFS のためのデータ構造
    queue<pair<ll, ll>> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    que.push(start); // 0 を橙色頂点にする
    field[start.first][start.second] = id;
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        pair<ll, ll> v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (pair<ll, ll> d : ds) {
            if(v.first + d.first < 0) {
                continue;
            }
            if(v.first + d.first >= (ll) field.size()) {
                continue;
            }
            if(v.second + d.second < 0) {
                continue;
            }
            if(v.second + d.second >= (ll) field.at(0).size()) {
                continue;
            }
            if (field[v.first + d.first][v.second + d.second] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            field[v.first + d.first][v.second + d.second] = id;
            que.push({v.first + d.first, v.second + d.second});
        }
    }
}

vector<ll> bfs_graph(const Graph &G, ll vertex) {
    // BFS のためのデータ構造
    vector<ll> dist(G.size(), -1); // 全頂点を「未訪問」に初期化
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[vertex] = 0;
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    return dist;
}

signed main() {
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

    vector<vector<ll>> field(H, vector<ll>(W, -1));
    REP(i, H) {
        REP(j, W) {
            if(S.at(i).at(j) == '#') {
                field.at(i).at(j) = INF;
            }
        }
    }

    ll id = 1;

    REP(i, H) {
        REP(j, W) {
            if(field.at(i).at(j) == -1) {
                bfs(field, {i, j}, id);
                id++;
            }
        }
    }

    set<pair<ll, ll>> edges;

    REP(i, H) {
        REP(j, W) {
            if(field.at(i).at(j) == INF) {
                continue;
            }
            for(ll k = -2; k <= 2; k++) {
                for(ll l = -2; l <= 2; l++) {
                    if(i + k < 0 || j + l < 0) {
                        continue;
                    }
                    if(i + k >= H || j + l >= W) {
                        continue;
                    }
                    if(field.at(i + k).at(j + l) == INF) {
                        continue;
                    }
                    if(field.at(i).at(j) == field.at(i + k).at(j + l)) {
                        continue;
                    }
                    edges.insert({min(field.at(i).at(j), field.at(i + k).at(j + l)), max(field.at(i).at(j), field.at(i + k).at(j + l))});
                }
            }
        }
    }

    Graph G(id + 1);

    for(auto edge : edges) {
        G[edge.first].push_back(edge.second);
        G[edge.second].push_back(edge.first);
    }

    vector<ll> dist = bfs_graph(G, field[Ch - 1][Cw - 1]);
    cout << dist[field[Dh - 1][Dw - 1]] << endl;
}