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
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 1; i * i <= 2 * N; i++) {
        if(2 * N % i == 0) {
            ll j = 2 * N / i;
            if(i % 2 == 0 and j % 2 == 0) {
                continue;
            }
            if(i % 2 == 1 and j % 2 == 1) {
                continue;
            }
            ans++;
        }
    }
    ans *= 2;
    cout << ans << endl;
    return 0;
}