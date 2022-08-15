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

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, ll &ans, vector<bool> &seen) {
    seen[v] = true; // v を訪問済にする
    ans++;

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, ans, seen); // 再帰的に探索
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    // 辺の情報
    vector<pair<ll, ll>> edges(M);
    for(ll i = 0; i < M; i++) {
        cin >> edges.at(i).first >> edges.at(i).second;
        edges.at(i).first--;
        edges.at(i).second--;
    }
    // グラフを作成 (ここでは有向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
    }

    // 頂点 0 をスタートとした探索
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
         vector<bool> seen;
        seen.assign(N, false); // 全頂点を「未訪問」に初期化
        dfs(G, i, ans, seen);
    }
    cout << ans << endl;
    return 0;
}