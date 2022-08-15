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

void bfs(const Graph &G, ll vertex, vector<bool> &seen, ll &ans, const vector<ll> &A) {
    // BFS のためのデータ構造
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    seen[vertex] = true;
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            ans = max(ans, A.at(nv) - A.at(vertex));
            if(seen[nv]) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            seen[nv] = true;
            que.push(nv);
        }
    }

    return;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    // 辺の情報
    vector<pair<ll, ll>> edges(M);
    for(ll i = 0 ; i < M; i++) {
        cin >> edges.at(i).first >> edges.at(i).second;
        edges.at(i).first--;
        edges.at(i).second--;
    }
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
    }

    vector<pair<ll, ll>> B(N);
    for(ll i = 0; i < N; i++) {
        B.at(i).first = A.at(i);
        B.at(i).second = i;
    }
    sort(ALL(B));

    ll ans = -INF;

    vector<bool> seen(N, false);
    for(ll i = 0; i < N; i++) {
        ll j = B.at(i).second;
        if(!seen.at(j)) {
            bfs(G, j, seen, ans, A);
        }
    }

    cout << ans << endl;
    return 0;
}