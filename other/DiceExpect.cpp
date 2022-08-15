#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll K;
    cin >> K;
    vector<long double> dp(K + 6, 0);
    for(ll i = K - 1; i >= 0; i--) {
        for(ll j = 1; j <= 6; j++) {
            dp.at(i) += (dp.at(i + j) + 1) / 6;
        }
    }
    cout << fixed << setprecision(20) << dp.at(0) << endl;
    return 0;
}