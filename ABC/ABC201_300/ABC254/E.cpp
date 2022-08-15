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

using Graph = vector<vector<ll>>;

void bfs(const Graph &G, map<ll, ll> &dist, ll vertex, vector<vector<ll>> &ans) {
    // BFS のためのデータ構造
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[vertex] = 0;
    ans.at(vertex).at(0) += (vertex + 1);
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        
        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            if (dist.count(nv)) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            if(dist[nv] <= 3) {
                ans.at(vertex).at(dist[nv]) += (nv + 1);
                que.push(nv);
            }
        }
    }

    return;
}

int main() {
    // 頂点数と辺数
    ll N, M;
    cin >> N >> M;

    vector<ll> a(M), b(M);
    for(ll i = 0; i < M; i++) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }

    ll Q;
    cin >> Q;

    vector<ll> x(Q), k(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i) >> k.at(i);
        x.at(i)--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    vector<vector<ll>> ans(N, vector<ll>(4));
    for(ll i = 0; i < N; i++) {
        map<ll, ll> dist;
        bfs(G, dist, i, ans);
    }

    for(ll i = 0; i < Q; i++) {
        ll res = 0;
        for(ll j = 0; j <= k.at(i); j++) {
            res += ans.at(x.at(i)).at(j);
        }
        cout << res << endl;
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    //for (ll v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
    /*
        0: 0
        1: 1
        2: 1
        3: 2
        4: 1
        5: 2
        6: 3
        7: 3
        8: 2
    */
    return 0;
}