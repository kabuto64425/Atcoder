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
    vector<ll> a(N, 0);
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<ll> dp(N, INF);
    dp[0] = 0;
    for(ll i = 1; i < N; i++) {
        if(i == 1) {
            dp[i] = dp[0] + abs(a[i] - a[i - 1]);
        }
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[N - 1] << endl;
    return 0;
}