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

bool solve(ll mid, ll N, ll i) {
   if(N / mid >= i) {
       return true;
   }
   return false;
}

int main(){
    ll N;
    cin >> N;
    ll index = 0;
    ll i = N;
    ll ans = 0;
    while(index < N) {
        ll ok = index;
        ll ng = N + 1;
        while(abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if(solve(mid, N, i)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans += (ok - index) * i;
        index = ok;
        i--;
    }
    cout << ans << endl;
    return 0;
}