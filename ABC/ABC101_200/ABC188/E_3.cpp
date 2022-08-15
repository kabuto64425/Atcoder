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
    Graph Greverse(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
        Greverse[edges[i].second].push_back(edges[i].first);
    }
    vector<ll> dp(N, INF);
    dp.at(0) = A.at(0);
    ll ans = -INF;
    for(ll v = 1; v < N; v++) {
        for(ll j = 0; j < (ll) Greverse.at(v).size(); j++) {
            dp.at(v) = min(dp.at(v), dp.at(Greverse.at(v).at(j)));
        }
        ans = max(ans, A.at(v) - dp.at(v));
        if(ans == 951328825) {
            cout << v << endl;
        }
        dp.at(v) = min(dp.at(v), A.at(v));
    }
    cout << ans << endl;
    return 0;
}