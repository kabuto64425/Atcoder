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
    ll A, B;
    cin >> A >> B;
    ll ans = -INF;
    ans = max(ans, 900 + A % 100 - B);
    ans = max(ans, 90 + ((A / 100) * 100 + A % 10) - B);
    ans = max(ans, 9 + (A / 10) * 10 - B);
    ans = max(ans, A - (100 + B % 100));
    ans = max(ans, A - ((B / 100) * 100 + B % 10));
    ans = max(ans, A - (B / 10) * 10);
    cout << ans << endl;
    return 0;
}