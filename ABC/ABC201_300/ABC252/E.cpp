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

typedef long long ll;
struct Edge {
    long long to;
    long long cost;
    long long number;
};
using Graph = vector<vector<Edge>>;
const long long INF = 1LL << 60;

/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<ll> &pre) {
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s, -1);
    tuple<ll, ll, ll> prep = {-1, -1, -1};
    while (!pq.empty()) {
        tuple<ll, ll, ll> p = pq.top();
        pq.pop();
        int v = get<1>(p);
        //pre.at(get<1>(p)) = get<2>(p);
        if (dis[v] < get<0>(p)) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to, e.number);
                pre.at(e.to) = e.number;
            }
        }
        prep = p;
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
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll>> ABC(M);
    for(tuple<ll, ll, ll> &abc : ABC) {
        cin >> get<0>(abc) >> get<1>(abc) >> get<2>(abc); 
    }
    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[get<0>(ABC[i]) - 1].push_back({get<1>(ABC[i]) - 1, get<2>(ABC[i]), i + 1});
        G[get<1>(ABC[i]) - 1].push_back({get<0>(ABC[i]) - 1, get<2>(ABC[i]), i + 1});
    }
    vector<ll> dist;
    vector<ll> pre(N, -1);
    dijkstra(G, 0, dist, pre);
    // distには1から各頂点への最短距離が入る
    vector<bool> flags(M + 1, false);
    for(ll i = 0; i < N; i++) {
        if(pre.at(i) != -1) {
            flags.at(pre.at(i)) = true;
        }
    }
    for(ll i = 1; i <= M; i++) {
        if(flags.at(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}