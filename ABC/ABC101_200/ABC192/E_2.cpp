#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

using namespace std;
typedef long long ll;
struct Edge {
    long long to;
    long long cost;
    long long interval;
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
            ll arrivalTime = e.cost + (e.interval - (dis[v] % e.interval)) % e.interval;
            if (dis[e.to] > dis[v] + arrivalTime) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + arrivalTime;
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
    vector<tuple<ll, ll, ll, ll>> ABTK(M);
    for(tuple<ll, ll, ll, ll> &abtk : ABTK) {
        cin >> get<0>(abtk) >> get<1>(abtk) >> get<2>(abtk) >> get<3>(abtk); 
    }
    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[get<0>(ABTK[i]) - 1].push_back({get<1>(ABTK[i]) - 1, get<2>(ABTK[i]), get<3>(ABTK[i])});
        G[get<1>(ABTK[i]) - 1].push_back({get<0>(ABTK[i]) - 1, get<2>(ABTK[i]), get<3>(ABTK[i])});
    }
    vector<ll> dist;
    dijkstra(G, X - 1, dist);
    // distには1から各頂点への最短距離が入る
    if(dist.at(Y - 1) == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist.at(Y - 1) << endl;
    return 0;
}