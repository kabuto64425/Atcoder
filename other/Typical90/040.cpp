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

int main(){
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N);
    for(ll &a: A) {
        cin >> a;
    }

    mf_graph<ll> G(N + 2);

    // 埋める
    ll s = 0;
    // 燃やす
    ll t = N + 1;

    for(ll i = 1; i <= N; i++) {
        // 埋めるコスト
        G.add_edge(s, i, A.at(i - 1));
        // 燃やすコスト
        G.add_edge(i, t, W);
    }

    for(ll i = 1; i <= N; i++) {
        ll k;
        cin >> k;
        for(ll j = 0; j < k; j++) {
            ll c;
            cin >> c;
            G.add_edge(c, i, INF);
        }
    }

    ll X = G.flow(s, t);

    ll ans = accumulate(A.begin(), A.end(), 0LL);
    ans -= X;

    cout << ans << endl;

    return 0;
}