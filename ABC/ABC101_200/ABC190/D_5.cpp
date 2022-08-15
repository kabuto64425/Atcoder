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
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 1; i * i <= 2 * N; i++) {
        if(2 * N % i != 0) {
            continue;
        }
        ll div = 2 * N / i;
        if((div % 2 == 0 and i % 2 == 1) or (div % 2 == 1 and i % 2 == 0)) {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}