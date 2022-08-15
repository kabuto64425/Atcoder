#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll L, X, Y, S, D;
    cin >> L >> X >> Y >> S >> D;
    long double ans;
    if(D > S) {
        if(Y <= X) {
            ans = (D - S) / (long double)(Y + X);
        } else {
            ans = min((D - S) / (long double)(Y + X), (L + S - D) / (long double)(Y - X));
        }
    } else {
        if(Y <= X) {
            ans = (L + D - S) / (long double)(Y + X);
        } else {
            ans = min((L + D - S) / (long double)(Y + X), (S - D) / (long double)(Y - X));
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}