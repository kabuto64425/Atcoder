#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis) {
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = INF;
    pq.emplace(dis[s], s);
    bool isFirst = true;
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        if(isFirst) {
            for (auto &e : G[v]) {
                dis[e.to] = min(dis[e.to], e.cost);
                pq.emplace(dis[e.to], e.to);
            }
            isFirst = false;
        } else {
            for (auto &e : G[v]) {
                if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                    dis[e.to] = dis[v] + e.cost;
                    pq.emplace(dis[e.to], e.to);
                }
            }
        }
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll>> ABC(M);
    for(tuple<ll, ll, ll> &abc : ABC) {
        cin >> get<0>(abc) >> get<1>(abc) >> get<2>(abc);
    }
    // グラフを作成 (ここでは有向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[get<0>(ABC[i]) - 1].push_back({get<1>(ABC[i]) - 1, get<2>(ABC[i])});
    }
    for(ll i = 0; i < N; i++) {
        vector<ll> dis;
        dijkstra(G, i, dis);
        if(dis.at(i) == INF) {
            cout << -1 << endl;
        } else {
            cout << dis[i] << endl;
        }
    }
    return 0;
}