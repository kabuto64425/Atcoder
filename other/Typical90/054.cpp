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

using Graph = vector<vector<ll>>;

vector<ll> bfs(const Graph &G, ll vertex) {
    // BFS のためのデータ構造
    vector<ll> dist(G.size(), -1); // 全頂点を「未訪問」に初期化
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[vertex] = 0;
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    return dist;
}

int main(){
    ll N, M;
    cin >> N >> M;

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N + M);
    for (ll i = 0; i < M; ++i) {
        ll K;
        cin >> K;
        vector<ll> R(K);
        for(ll &r : R) {
            cin >> r;
            r--;
        }
        for(const ll &r : R) {
            G[r].push_back(N + i);
            G[N + i].push_back(r);
        }
    }

    vector<ll> dist = bfs(G, 0);

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (ll v = 0; v < N; v++) {
        if(dist[v] == -1) {
            cout << -1 << endl;
        } else {
            cout << dist[v] / 2 << endl;
        }
    }
    return 0;
}