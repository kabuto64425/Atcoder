#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    string S;
    cin >> S;
    ll X1 = atoi(S.substr(0, 3).c_str());
    ll ans = abs(X1 - 753);
    for(ll i = 1; i < S.length() - 2; i++) {
        ll Xi = atoi(S.substr(i, 3).c_str());
        ans = min(ans, abs(Xi - 753));
    }
    cout << ans << endl;
}