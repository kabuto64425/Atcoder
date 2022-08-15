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

ll func(ll a, ll b) {
    ll res = 0;
    res += a * a * a;
    res += a * a * b;
    res += a * b * b;
    res += b * b * b;
    return res;
}

int main(){
    ll N;
    cin >> N;
    ll ans = INF;
    for(ll a = 0; a <= 1000000; a++) {
        ll ok = 1000000;
        ll ng = -1;
        while(abs(ok - ng) != 1) {
            ll mid = (ok + ng) / 2;
            if(func(a, mid) >= N) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans = min(ans, func(a, ok));
    }
    cout << ans << endl;
    return 0;
}