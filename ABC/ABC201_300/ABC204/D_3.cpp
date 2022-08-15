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
    vector<ll> T(N);
    for(ll &t : T) {
        cin >> t;
    }
    ll sum = accumulate(ALL(T), 0LL);
    vector<vector<bool>> dp(N + 1,vector<bool>(110000, false));
    dp.at(0).at(0) = true;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= sum; j++) {
            dp.at(i).at(j) = dp.at(i).at(j) | dp.at(i - 1).at(j);
            if(j - T.at(i - 1) >= 0) {
                dp.at(i).at(j) = dp.at(i).at(j) | dp.at(i - 1).at(j - T.at(i - 1));
            }
        }
    }
    ll ans = INF;
    for(ll j = 0; j <= sum; j++) {
        if(dp.at(N).at(j)) {
            ans = min(ans, max(j, sum - j));
        }
    }
    cout << ans << endl;
    return 0;
}