#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<ll> &ans, vector<bool> &seen) {

    seen[v] = true;

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if(seen[next_v]) {
            continue;
        }
        ans[next_v] += ans[v];
        dfs(G, next_v, ans, seen); // 再帰的に探索
    }
}

int main() {
    ll N , Q;
    cin >> N >> Q;

    Graph G(N);
    for (ll i = 0; i < N - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> ans(N, 0);
    for(ll i = 0; i < Q; i++) {
        ll p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }

    // 頂点 0 をスタートとした探索
    vector<bool> seen(N, false);
    dfs(G, 0, ans, seen);
    for(const ll &a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}