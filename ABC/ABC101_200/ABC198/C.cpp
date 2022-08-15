#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll R, X, Y;
    cin >> R >> X >> Y;
    if(R * R == (X * X + Y * Y)) {
        cout << 1 << endl;
        return 0;
    }
    if(R * R > (X * X + Y * Y)) {
        cout << 2 << endl;
        return 0;
    }
    ll d = X * X + Y * Y;
    ll ans = 0;
    while((ans + 1) * (ans + 1) * R * R < d) {
        ans++;
    }
    cout << ans + 1 << endl;
    return 0;
}