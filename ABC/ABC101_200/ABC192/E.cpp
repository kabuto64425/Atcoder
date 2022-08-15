#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge {
    long long to;
    long long cost;
    long long num;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis, const vector<tuple<ll, ll, ll, ll>> &ABTK) {
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            ll cost = 0;
            cost += ((dis[v] + (get<3>(ABTK[e.num]) - 1)) / get<3>(ABTK[e.num])) * get<3>(ABTK[e.num]) - dis[v];
            cost += e.cost;
            if (dis[e.to] > dis[v] + cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main() {
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<tuple<ll, ll, ll, ll>> ABTK(M);
    for(tuple<ll, ll, ll, ll> &abtk : ABTK) {
        cin >> get<0>(abtk) >> get<1>(abtk) >> get<2>(abtk) >> get<3>(abtk);
    }
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[get<0>(ABTK[i]) - 1].push_back({get<1>(ABTK[i]) - 1, get<2>(ABTK[i]), i});
        G[get<1>(ABTK[i]) - 1].push_back({get<0>(ABTK[i]) - 1, get<2>(ABTK[i]), i});
    }

    vector<ll> dis;
    dijkstra(G, X - 1, dis, ABTK);
    if(dis.at(Y - 1) == INF) {
        cout << -1 << endl;
    } else {
        cout << dis.at(Y - 1) << endl;
    }

    return 0;
}