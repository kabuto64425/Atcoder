#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    FOR(i, K, N + 1) {
        ll left = ((2 * N - i + 1) * i / 2);
        ll right = ((i - 1) * i / 2);
        ans += left - right + 1;
    }
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}