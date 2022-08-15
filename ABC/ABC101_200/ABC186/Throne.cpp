#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll solve(ll N, ll S, ll K) {
    ll d = gcd(K, N);
    if(S % d != 0) {
        return -1;
    }
    N /= d;
    S /= d;
    K /= d;
    modint::set_mod(N);
    modint res = -modint(S) / K;
    return res.val();
}

int main(){
    ll T;
    cin >> T;
    REP(i, T) {
        ll N, S, K;
        cin >> N >> S >> K;
        cout << solve(N, S, K) << endl;
    }
    return 0;
}