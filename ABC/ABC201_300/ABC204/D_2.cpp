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
    vector<ll> T(N);
    ll sum = 0;
    for(ll &t : T) {
        cin >> t;
        sum += t;
    }
    vector<bool> dp(110000, false);
    dp.at(0) = true;
    for(ll i = 0; i < N; i++) {
        ll t = T.at(i);
        for(ll j = 0; j <= 100000; j++) {
            if(j - t >= 0 and dp.at(j - t)) {
                dp.at(j) = dp.at(j - t);
            }
        }
    }
    ll ans = INF;
    for(ll i = 0; i <= sum; i++) {
        if(dp.at(i)) {
            ans = min(ans, max(i, sum - i));
        }
    }
    cout << ans << endl;
    return 0;
}