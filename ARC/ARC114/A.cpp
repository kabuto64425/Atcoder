#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = LLONG_MAX; //10^18:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> X(N);
    for(ll &x : X) {
        cin >> x;
    }
    const vector<ll> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    ll ans = INF;
    for(ll bit = 1; bit < (1 << 15); bit++) {
        ll num = 1;
        for(ll i = 0; i < 15; i++) {
            if(bit & (1 << i)) {
                num *= primes.at(i);
            }
        }
        ll flag = true;
        for(const ll &x : X) {
            if(gcd(x, num) == 1) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans = min(ans, num);
        }
    }
    cout << ans << endl;
    return 0;
}