#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> L(K), R(K);
    for(ll i = 0; i < K; i++) {
        cin >> L.at(i) >> R.at(i);
    }
    vector<mint> dp(N + 1, 0);
    vector<mint> csum(N + 1, 0);
    dp.at(1) = 1;
    csum.at(1) = 1;
    for(ll i = 2; i <= N; i++) {
        for(ll j = 0; j < K; j++) {
            ll l = max(i - R.at(j) - 1, 0LL);
            ll r = max(i - L.at(j), 0LL);

            dp.at(i) += csum.at(r) - csum.at(l);
        }
        csum.at(i) += csum.at(i - 1) + dp.at(i);
    }
    cout << dp.at(N).val() << endl;
    return 0;
}