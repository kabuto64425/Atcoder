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
    set<ll> s;
    ll ans = INF;
    for(ll a = 0; a <= 1000000; a++) {
        ll ok = 1000000;
        ll ng = -1;
        while(abs(ng - ok) != 1) {
            ll mid = (ok + ng) / 2;
            ll x = a * a * a + a * a * mid + a * mid * mid + mid * mid * mid;
            if(x >= N) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans = min(ans, a * a * a + a * a * ok + a * ok * ok + ok * ok * ok);
    }
    cout << ans << endl;
    return 0;
}