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
    ll K, S;
    cin >> K >> S;
    ll ans = 0;
    for(ll X = 0; X <= K; X++) {
        for(ll Y = 0; Y <= K; Y++) {
            ll Z = S - X - Y;
            if(Z >= 0 and Z <= K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}