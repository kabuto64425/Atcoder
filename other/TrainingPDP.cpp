#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<vector<long double>> dp(N + 1, vector<long double>(6 * N + 1));
    dp[0][0] = 1.0;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 6 * N; j++) {
            for(ll me = 1; me <= 6; me++) {
                if(j - me >= 0) {
                    dp[i][j] += dp[i - 1][j - me] / 6;
                }
            }
        }
    }
    long double ans = 0;
    for(ll i = K; i <= 6 * N; i++) {
        ans += dp[N][i];
    }
    cout << ans << endl;
    return 0;
}