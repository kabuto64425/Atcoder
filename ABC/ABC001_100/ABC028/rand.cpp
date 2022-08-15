#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    ans += (K - 1) * (N - K) * 6;
    ans += (K - 1) * 3;
    ans += (N - K) * 3;
    ans += 1;
    cout<< fixed << setprecision(20) << ans / (long double)(N * N * N) << endl;
}