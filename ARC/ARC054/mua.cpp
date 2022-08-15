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
    long double p;
    cin >> p;
    long double ok = 0;
    long double ng = 1000000000000000001;
    while(abs(ok - ng) >= 0.00000000001) {
        long double mid = (ok + ng) / 2;
        if((- (p / 1.5) * pow(2, -mid / 1.5) * log(2) + 1) >= 0) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    cout << fixed << setprecision(20) << (ok + p * pow(2, -ok / 1.5)) << endl;
}