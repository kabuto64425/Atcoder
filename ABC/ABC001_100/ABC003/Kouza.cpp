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
    vector<ll> R(N);
    for(ll &r: R) {
        cin >> r;
    }
    sort(R.begin(), R.end(), greater<ll>());
    long double ans = 0.0;
    REP(i, K) {
        ans = (ans + R.at(K - i - 1)) / 2;
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}