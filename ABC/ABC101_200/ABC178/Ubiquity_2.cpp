#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

mint pow_self(ll a, ll r) {
    mint res = 1;
    REP(i, r) {
        res *= a;
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    mint ans = 0;
    ans = pow_self(10, N);
    ans -= pow_self(9, N);
    ans -= pow_self(9, N);
    ans += pow_self(8, N);
    cout << ans.val() << endl;
    return 0;
}