#include <bits/stdc++.h>
using namespace std;
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
    for(ll &t : T) {
        cin >> t;
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(100001, false));
    dp.at(0).at(0) = true;
    for(ll i = 1; i <= N; i++) {
        ll time = T.at(i - 1);
        for(ll t = 0; t <= 100000; t++) {
            dp.at(i).at(t) = dp.at(i).at(t) | dp.at(i - 1).at(t);
            if(t - time >= 0) {
                dp.at(i).at(t) = dp.at(i).at(t) | dp.at(i - 1).at(t - time);
            }
        }
    }
    ll ans = INF;
    ll sum = accumulate(T.begin(), T.end(), 0LL);
    for(ll t = 0; t <= 100000; t++) {
        if(dp.at(N).at(t)){
            ans = min(ans, max(sum - t, t));
        }
    }
    cout << ans << endl;
    return 0;
}