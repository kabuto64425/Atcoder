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
    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    ll X = K;
    ll ans = 0;
    if(K > A) {
        X = K - A;
        ans += A;
    } else {
        ans += K;
        cout << ans << endl;
        return 0;
    }

    if(X > B) {
        X = X - B;
    } else {
        cout << ans << endl;
        return 0;
    }

    if(X > C) {
        ans -= C;
    } else {
        ans -= X;
    }
    cout << ans << endl;
    return 0;
}