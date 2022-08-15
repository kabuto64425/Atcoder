#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

long double f(long double x, long double p) {
    return (x + p * pow(2, -x / 1.5));
}

signed main(){
    long double p;
    cin >> p;
    long double left = 0;
    long double right = 1000000000000000001;
    while(abs(right - left) >= 0.00000000001) {
        long double c1 = (left * 2 + right) / 3;
        long double c2 = (left + right * 2) / 3;

        if(f(c1, p) >= f(c2, p)) {
            left = c1;
        } else {
            right = c2;
        }

    }
    cout << fixed << setprecision(20) << f(left, p) << endl;
}