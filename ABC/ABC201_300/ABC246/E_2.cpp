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
/*struct Edge {
    long long to;
    long long cost;
};*/
struct Bishop {
    long long x;
    long long y;
    long long d;
};
const long long INF = 1LL << 60;

vector<pair<ll, ll>> ds = {
    {-1, -1},
    {-1, 1},
    {1, 1},
    {1, -1}
};

/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(ll N, const vector<string> &S, const ll Ax, ll Ay, vector<vector<vector<ll>>> &dis) {
    priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>, greater<tuple<ll, ll, ll, ll>>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[Ax][Ay][0] = 0;
    dis[Ax][Ay][1] = 0;
    dis[Ax][Ay][2] = 0;
    dis[Ax][Ay][3] = 0;
    pq.emplace(dis[Ax][Ay][0], Ax, Ay, 0);
    pq.emplace(dis[Ax][Ay][1], Ax, Ay, 1);
    pq.emplace(dis[Ax][Ay][2], Ax, Ay, 2);
    pq.emplace(dis[Ax][Ay][3], Ax, Ay, 3);
    while (!pq.empty()) {
        tuple<ll, ll, ll, ll> p = pq.top();
        pq.pop();
        Bishop v{get<1>(p), get<2>(p), get<3>(p)};
        if (dis[v.x][v.y][v.d] < get<0>(p)) {  // 最短距離で無ければ無視
            continue;
        }
        for(ll i = 0; i < 4; i++) {
            pair<ll, ll> to = {v.x + ds.at(i).first, v.y + ds.at(i).second};
            if(to.first < 0) {
                continue;
            }
            if(to.first >= N) {
                continue;
            }
            if(to.second < 0) {
                continue;
            }
            if(to.second >= N) {
                continue;
            }
            if(S.at(to.first).at(to.second) == '#') {
                continue;
            }
            ll cost = 1;
            if(v.d == i) {
                cost = 0;
            }
            if(dis[to.first][to.second][i] > dis[v.x][v.y][v.d]) {
                dis[to.first][to.second][i] = dis[v.x][v.y][v.d] + cost;
                pq.emplace(dis[to.first][to.second][i], to.first, to.second, i);
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
    ll N;
    cin >> N;
    ll Ax, Ay;
    cin >> Ax >> Ay;
    ll Bx, By;
    cin >> Bx >> By;
    vector<string> S(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i);
    }
    vector<vector<vector<ll>>> dist(N, vector<vector<ll>>(N, vector<ll>(4, INF)));
    dijkstra(N, S, Ax - 1, Ay - 1, dist);
    // distには1から各頂点への最短距離が入る
    ll ans = INF;
    for(ll i = 0; i < 4; i++) {
        ans = min(ans, dist[Bx - 1][By - 1][i]);
    }
    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    ans++;
    cout << ans << endl;
    return 0;
}
