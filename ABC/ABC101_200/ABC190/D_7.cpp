#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    ll M = 2 * N;
    ll ans = 0;
    for(ll i = 1; i * i <= M; i++) {
        if(M % i != 0) {
            continue;
        }
        ll x = i;
        ll y = M / i;
        if(x % 2 == 0 and y % 2 == 0) {
            continue;
        }
        if(x % 2 == 1 and y % 2 == 1) {
            continue;
        }
        ans++;
    }
    ans *= 2;
    cout << ans << endl;
    return 0;
}