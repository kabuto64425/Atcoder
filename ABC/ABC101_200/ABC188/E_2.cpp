#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

void bfs(const Graph &G, const vector<pair<ll, ll>> &A, ll vertex, vector<bool> &seen, ll &ans) {
    // BFS のためのデータ構造
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            if (seen.at(nv)) continue; // すでに発見済みの頂点は探索しない

            ans = max(ans, A.at(nv).first - A.at(vertex).first);

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            seen.at(nv) = true;
            que.push(nv);
        }
    }
}

int main(){
    // 頂点数と辺数
    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i).first;
        A.at(i).second = i;
    }

    // 辺の情報
    vector<pair<ll, ll>> edges(M);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
    }

    vector<pair<ll, ll>> B = A;
    sort(B.begin(), B.end());

    ll ans = -INF;

    vector<bool> seen(N, false);

    for(ll i = 0; i < N; i++) {
        bfs(G, A, B.at(i).second, seen, ans);
    }

    cout << ans << endl;

    return 0;
}