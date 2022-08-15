#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

// 深さ優先探索
void dfs(const Graph &G, ll i, ll parent, vector<ll> &ans, vector<bool> &seen) {
    seen.at(i) = true;
    if(parent != -1) {
        ans.at(i) += ans.at(parent);
    }

    // v から行ける各頂点 next_v について
    for (auto next_v : G[i]) {
        if(seen.at(next_v)) {
            continue;
        }
        dfs(G, next_v, i, ans, seen); // 再帰的に探索
    }
}

signed main() {
    // 頂点数と辺数
    ll N, Q;
    cin >> N >> Q;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        ll a;
        ll b;
        cin >> a >> b;
        a--;
        b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    // 頂点 0 をスタートとした探索
    vector<ll> ans(N, 0);
    REP(i, Q) {
        ll p, x;
        cin >> p >> x;
        p--;
        ans.at(p) += x;
    }

    vector<bool> seen;
    seen.assign(N, false);
    dfs(G, 0, -1, ans, seen);

    REP(i, N) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
}