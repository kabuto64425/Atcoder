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
    ll N, Y;
    cin >> N >> Y;
    FOR(i, 0, N) {
        FOR(j, 0, N - i) {
            if(10000 * i + 5000 * j + 1000 * (N - i - j) == Y) {
                cout << i << " " << j << " " << (N - i - j) << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}