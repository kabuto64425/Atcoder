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
    string S;
    cin >> S;
    ll ans = 0;
    for(long unsigned int i = 0; i <= S.length() - 1; i++) {
        for(long unsigned int j = i; j <= S.length() - 1; j++) {
            bool flag = true;
            ll len = j - i + 1;
            for(long unsigned int k = i; k <= j; k++) {
                char c = S.at(k);
                if(c != 'A' && c != 'G' && c != 'C' && c != 'T') {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans = max(ans, len);
            }
        }
    }
    cout << ans << endl;
}