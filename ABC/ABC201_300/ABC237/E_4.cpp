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

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

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
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for(ll i = 0; i < N; i++) {
        cin >> H.at(i);
    }
    vector<ll> U(M), V(M);
    for(ll i = 0; i < M; i++) {
        cin >> U.at(i) >> V.at(i);
    }
    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[U.at(i) - 1].push_back({V.at(i) - 1,max(H.at(V.at(i) - 1) - H.at(U.at(i) - 1), 0LL)});
        G[V.at(i) - 1].push_back({U.at(i) - 1,max(H.at(U.at(i) - 1) - H.at(V.at(i) - 1), 0LL)});
    }
    vector<ll> dist;
    dijkstra(G, 0, dist);
    // distには1から各頂点への最短距離が入る
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ll current = H.at(0) - H.at(i);
        current -= dist.at(i);
        ans = max(ans, current);
    }
    cout << ans << endl;
    return 0;
}