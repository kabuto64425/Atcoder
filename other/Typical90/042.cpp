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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll K;
    cin >> K;
    if(K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<mint> dp(110000, 0);
    dp.at(0) = 1;
    for(ll i = 1; i <= 100000; i++) {
        for(ll j = max(i - 9, 0LL); j < i; j++) {
            dp.at(i) += dp.at(j);
        }
    }
    cout << dp.at(K).val() << endl;
    return 0;
}