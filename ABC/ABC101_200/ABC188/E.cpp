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

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }

    // 辺の情報
    vector<pair<ll, ll>> edges(M);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    // グラフを作成
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
    }

    for (ll i = 0; i < N; ++i) {
        sort(G[i].begin(), G[i].end());
    }

    vector<ll> dp(N, INF);

    for(ll i = 0; i < N; i++) {
        for (ll j : G[i]) {
            dp.at(j) = min({dp.at(j), dp.at(i), A.at(i)});
        }
    }

    ll ans = -INF;

    for(ll i = 0; i < N; i++) {
        ans = max(ans, A.at(i) - dp.at(i));
    }

    cout << ans << endl;
    
    return 0;
}