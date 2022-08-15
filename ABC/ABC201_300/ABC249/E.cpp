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
    ll N, P;
    cin >> N >> P;
    vector<vector<ll>> dp(5000, vector<ll>(5000, 0));
    dp[0][0] = 1;
    dp[0][1] = (-1 + P) % P;
    for(ll i = 0; i < N; i++) {
        // imos法
        for(ll j = 1; j <= N; j++){
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= P;
        }
        ll c = 25;
        if(i == 0) {
            c = 26;
        }
        for(ll j = 0; j <= N; j++) {
            ll x = dp.at(i).at(j) % P;
            ll y = (c * x) % P;
            ll z = (-y + P) % P;
            dp.at(i + 2).at(j + 1) += y;
            dp.at(i + 2).at(j + 1) %= P;

            dp.at(i + 2).at(j + 10) += z;
            dp.at(i + 2).at(j + 10) %= P;

            dp.at(i + 3).at(j + 10) += y;
            dp.at(i + 3).at(j + 10) %= P;

            dp.at(i + 3).at(j + 100) += z;
            dp.at(i + 3).at(j + 100) %= P;

            dp.at(i + 4).at(j + 100) += y;
            dp.at(i + 4).at(j + 100) %= P;

            dp.at(i + 4).at(j + 1000) += z;
            dp.at(i + 4).at(j + 1000) %= P;

            dp.at(i + 5).at(j + 1000) += y;
            dp.at(i + 5).at(j + 1000) %= P;
        }
    }
    ll ans = 0;
    for(ll i = 1; i < N; i++) {
        ans += dp.at(i).at(N);
        ans %= P;
    }
    cout << ans << endl;
    return 0;
}