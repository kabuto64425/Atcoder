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
    long double Sx, Sy, Gx, Gy;
    cin >> Sx >> Sy >> Gx >> Gy;
    long double ans = Gx - Gy * (Gx - Sx) / (Gy + Sy);
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}