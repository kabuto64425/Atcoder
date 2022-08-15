#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<bool> &seen, vector<ll> &ans) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        ll to = next_v.to;
        ll cost = next_v.cost;
        if (seen[to]) continue;
        if(cost % 2 == 0) {
            ans[to] = ans[v];
        } else {
            ans[to] = 1 - ans[v];
        }

        dfs(G, to, seen, ans); // 再帰的に探索
    }
}

int main() {
    
    // 頂点数と辺数
    ll N = 7;
    cin >> N;

    vector<tuple<ll, ll, ll>> uvw(N - 1);
    for(tuple<ll, ll, ll> &elm : uvw) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N - 1; i++) {
        G[get<0>(uvw[i]) - 1].push_back({get<1>(uvw[i]) - 1, get<2>(uvw[i])});
        G[get<1>(uvw[i]) - 1].push_back({get<0>(uvw[i]) - 1, get<2>(uvw[i])});
    }

    vector<ll> ans(N);
    ans.at(0) = 1;

    vector<bool> seen;
    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, seen, ans);
    // 結果出力
    for(ll i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}