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
    ll N;
    cin >> N;
    ll NG1, NG2, NG3;
    cin >> NG1 >> NG2 >> NG3;
    vector<ll> dp(N + 1, INF);
    for(ll i = N; i >= 0; i--) {
        if(i == NG1 or i == NG2 or i == NG3) {
            continue;
        }
        if(i == N) {
            dp[i] = 0;
            continue;
        }
        ll x = dp[i];
        
        if(i <= N - 1) {
            x = min(x, dp[i + 1] + 1);
        }
        if(i <= N - 2) {
            x = min(x, dp[i + 2] + 1);
        }
        if(i <= N - 3) {
            x = min(x, dp[i + 3] + 1);
        }
        dp[i] = x;
    }
    if(dp[0] <= 100) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}