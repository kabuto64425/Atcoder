#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll S;
    cin >> S;
    vector<mint> dp(2200, 0);
    vector<mint> sum(2200, 0);
    dp.at(0) = 1;
    sum.at(0) = 1;
    for(ll i = 1; i <= 2000; i++) {
        if(i < 3) {
            dp.at(i) = 0;
        } else {
            dp.at(i) = sum.at(i - 3);
        }
        sum.at(i) += dp.at(i) + sum.at(i - 1);
    }
    cout << dp.at(S).val() << endl;
    return 0;
}