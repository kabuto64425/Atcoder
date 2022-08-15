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

using namespace std;
typedef long long ll;
struct Edge {
    long long to;
    long long cost;
    long long span;
};
using Graph = vector<vector<Edge>>;
const long long INF = 1LL << 60;

/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis) {
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        pair<ll, ll> p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            ll wait = (e.span - dis[v] % e.span) % e.span;
            if (dis[e.to] > dis[v] + e.cost + wait) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost + wait;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

/*
  N:頂点の数
  M:辺の数
  ABC:各辺の結んだ頂点(get<0>(abc), get<1>(abc))とコスト(get<2>(abc))
  入力部分では1-indexedを想定。
  Graph Gとdijkstra内部では0-indexedで処理
*/
int main(){
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<ll> A(M), B(M), T(M), K(M);
    for(ll i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i) >> T.at(i) >> K.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[A.at(i)].push_back({B.at(i), T.at(i), K.at(i)});
        G[B.at(i)].push_back({A.at(i), T.at(i), K.at(i)});
    }
    vector<ll> dist;
    X--;
    Y--;
    dijkstra(G, X, dist);
    if(dist.at(Y) == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist.at(Y) << endl;
    // distには1から各頂点への最短距離が入る
    return 0;
}