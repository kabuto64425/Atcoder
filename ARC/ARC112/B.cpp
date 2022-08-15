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

int main(){
    ll B, C;
    cin >> B >> C;
    ll a = C / 2;
    if(B > 0) {
        ll ans = 1;
        if(C >= 2) {
            ans += C - 2;
        }
        ans += min(C, B * 2);
        cout << ans << endl;
    } else if(B == 0) {
        cout << max(C, 1LL) << endl;
    } else {
        ll ans = 1;
        ans += C;
        if(C >= 3) {
            ans += min(C - 2, abs(B) * 2 - 1);
        }
        cout << ans << endl;
    }
    return 0;
}