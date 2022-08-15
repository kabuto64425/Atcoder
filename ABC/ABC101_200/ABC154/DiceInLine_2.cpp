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
    vector<ll> p(N + 1);
    for(ll i = 1; i <= N; i++) {
        cin >> p[i];
    }
    vector<long double> sum(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + p[i] * (p[i] + 1) / (long double)(2 * p[i]);
    }
    long double ans = 0;
    for(ll i = K; i <= N; i++) {
        ans = max(ans, sum[i] - sum[i - K]);
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}