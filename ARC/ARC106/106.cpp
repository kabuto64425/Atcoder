#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N;
    cin >> N;
    ll X = 1;
    FOR(A, 1, 38) {
        X *= 3;
        ll Y = 1;
        FOR(B, 1, 26) {
            Y *= 5;
            if(N == X + Y) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}