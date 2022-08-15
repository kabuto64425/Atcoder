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
    ll N, K;
    cin >> N >> K;

    ll ans = 0;

    FOR (AB, 2, 2 * N) {
        ll x = AB - 1;
        if(AB > N + 1) {
            x -= 2 * (AB - (N + 1));
        }
        x = max(x, (ll) 0);
        ll CD = AB - K;
        ll y;
        if(CD < 2) {
            y = 0;
        } else {
            y = CD - 1;
            if(CD > N + 1) {
                y -= 2 * (CD - (N + 1));
            }
            y = max(y, (ll) 0);
        }
        ans += x * y;
    }

    cout << ans << endl;
}