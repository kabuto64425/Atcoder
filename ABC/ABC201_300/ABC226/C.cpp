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

void bfs(const Graph &G, vector<ll> &dist, ll vertex) {
    // BFS のためのデータ構造
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

    return;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> T(N), K(N);
    vector<vector<ll>> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> T.at(i) >> K.at(i);
        for(ll j = 0; j < K.at(i); j++) {
            ll x;
            cin >> x;
            A.at(i).push_back(x);
        }
    }

    Graph G(N);
    for(ll i = N - 1; i >= 0; i--) {
        for(ll j = 0; j < K.at(i); j++) {
            G[i].push_back(A.at(i).at(j) - 1);
        }
    }

    vector<ll> dist(N, -1);

    bfs(G, dist, N - 1);
    
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(dist.at(i) != -1) {
            ans += T.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}