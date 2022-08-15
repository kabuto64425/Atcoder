#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

vector<mint> bfs(const Graph &G, ll vertex) {
    // BFS のためのデータ構造
    vector<ll> dist(G.size(), -1); // 全頂点を「未訪問」に初期化
    vector<mint> ans(G.size(), 0);
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[vertex] = 0;
    ans[vertex] = 1;
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            if (dist[nv] != -1) {
                if(dist[nv] == dist[v] + 1) {
                    ans[nv] += ans[v];
                }
                continue;
            }

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            ans[nv] += ans[v];
            que.push(nv);
        }
    }

    return ans;
}

int main(){
    // 頂点数と辺数
    ll N;
    ll M;
    cin >> N >> M;

    // 辺の情報
    vector<pair<ll, ll>> edges(M);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }

    vector<mint> ans = bfs(G, 0);

    cout << ans.at(N - 1).val() << endl;
    return 0;
}