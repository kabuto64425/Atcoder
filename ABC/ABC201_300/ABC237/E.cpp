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

void bfs(const Graph &G, const vector<ll> &H, vector<ll> &dist, ll vertex) {
    // BFS のためのデータ構造
    //queue<ll> que;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll, ll>>> pq;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[vertex] = 0;
    //que.push(vertex); // 0 を橙色頂点にする
    pq.push({dist[vertex], 0});

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!pq.empty()) {
        pair<ll, ll> v = pq.top(); // キューから先頭頂点を取り出す
        pq.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v.second]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            if(H[v.second] > H[nv]) {
                dist[nv] = dist[v.second] + (H[v.second] - H[nv]);
            }else if(H[v.second] < H[nv]) {
                dist[nv] = dist[v.second] - (H[nv] - H[v.second]) * 2;
            }else {
                dist[nv] = dist[v.second];
            }

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            //que.push(nv);
            pq.push({dist[nv], nv});
        }
    }

    return;
}

int main(){
    
    // 頂点数と辺数
    ll N, M;
    cin >> N >> M;

    vector<ll> H(N);
    for(ll i = 0; i < N; i++) {
        cin >> H.at(i);
    }

    vector<ll> U(M), V(M);
    for(ll i = 0; i < M; i++) {
        cin >> U.at(i) >> V.at(i);
        U.at(i)--;
        V.at(i)--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[U.at(i)].push_back(V.at(i));
        G[V.at(i)].push_back(U.at(i));
    }

    vector<ll> dist(G.size(), -1); // 全頂点を「未訪問」に初期化
    bfs(G, H, dist, 0);

    ll ans = *max_element(ALL(dist));
    cout << ans << endl;
    return 0;
}