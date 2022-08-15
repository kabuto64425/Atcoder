#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll j = 1; j <= N; j += 2) {
        ll m = j;
        ll current = 1;
        for(ll i = 2; i * i <= m; i++) {
            ll num = 0;
            while(m % i == 0) {
                m = m / i;
                num++;
            }
            if(num != 0) {
                current *= (num + 1);
            }
        }
        if(m != 1) {
            current *= 2;
        }
        if(current == 8) {
            ans++;
        }
    }
    cout << ans << endl;
}