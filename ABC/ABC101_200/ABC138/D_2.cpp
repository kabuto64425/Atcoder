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

void dfs(const Graph &G, ll v, ll pre, vector<ll> &dp) {
    for(ll next_v : G[v]) {
        if(next_v == pre) {
            continue;
        }
        dp[next_v] += dp[v];
        dfs(G, next_v, v, dp);
    }
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N - 1), b(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    vector<ll> p(Q), x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> p.at(i) >> x.at(i);
        p.at(i)--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N - 1; ++i) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    vector<ll> dp(N);
    for(ll i = 0; i < Q; i++) {
        dp.at(p.at(i)) += x.at(i);
    }

    dfs(G, 0, -1, dp);

    for(ll i = 0; i < N; i++) {
        cout << dp.at(i) << " ";
    }

    cout << endl;

    return 0;
}