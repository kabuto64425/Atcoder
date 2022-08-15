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
    ll X, Y, A, B;
    cin >> X >> Y >> A >> B;
    ll ans = 0;
    while(X <= 1000000000000000000 / A and X * A < X + B and X * A < Y) {
        X *= A;
        ans++;
    }
    ans += (Y - 1 - X) / B;
    cout << ans << endl;
    return 0;
}