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

bool solve(ll mid, ll r, ll a) {
    if(mid * mid <= r * r - a * a) {
        return true;
    } else {
        return false;
    }
}

ll culc(ll r, ll a) {
    ll ok = 0;
    ll ng = r + 1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(mid, r, a)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main(){
    ll R;
    cin >> R;
    ll ans = 0;
    for(ll i = -R; i <= R; i++) {
        ans += culc(R, abs(i)) * 2 + 1;
    }
    cout << ans << endl;
    return 0;
}