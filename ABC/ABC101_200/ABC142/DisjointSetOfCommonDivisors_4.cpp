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
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    for(ll i = 2; i * i <= max(A, B); i++) {
        ll countA = 0;
        ll countB = 0;
        while(A % i == 0) {
            A /= i;
            countA++;
        }
        while(B % i == 0) {
            B /= i;
            countB++;
        }
        if(countA > 0 and countB > 0) {
            ans++;
        }
    }
    if(A != 1 and A == B) {
        ans += 2;
    } else {
        ans++;
    }
    cout << ans << endl;
    return 0;
}