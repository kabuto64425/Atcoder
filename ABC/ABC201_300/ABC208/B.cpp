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
    ll P;
    cin >> P;
    ll ans = 0;
    ll x = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    for(ll i = 10; i >= 1; i--) {
        ans += P / x;
        P = P % x;
        x /= i;
    }
    cout << ans << endl;
    return 0;
}