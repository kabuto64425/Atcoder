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
    ll T;
    cin >> T;
    REP(i, T) {
        ll L, R;
        cin >> L >> R;
        ll n = R - L * 2 + 1;
        if(n > 0) {
            cout << n * (n + 1) / 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}