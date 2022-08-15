#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    if(B % 4 == 2) {
        ll loop = ((C == 1)? 1 : 3);
        ll ans = (A % 10);
        for(ll i = 0; i < loop; i++) {
            ans *= (A % 10);
            ans %= 10;
        }
        cout << ans << endl;
        return 0;
    }
    ll bm = ((C % 2 == 0)? ((B % 4) * (B % 4)) : B % 4);
    ll ans = A % 10;
    ll loop = (bm + 3) % 4;
    for(ll i = 0; i < loop; i++) {
        ans *= (A % 10);
        ans %= 10;
    }
    cout << ans << endl;
    return 0;
}