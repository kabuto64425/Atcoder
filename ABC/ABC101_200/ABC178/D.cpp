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
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll S;
    cin >> S;
    vector<mint> dp(2200);
    vector<mint> csum(2200);
    dp.at(0) = 1;
    csum.at(0) = dp.at(0);
    dp.at(1) = 0;
    csum.at(1) = csum.at(0) + dp.at(1);
    dp.at(2) = 0;
    csum.at(0) = dp.at(0);
    csum.at(2) = csum.at(1) + dp.at(2);
    for(ll i = 3; i <= 2000; i++) {
        dp.at(i) += csum.at(i - 3);
        csum.at(i) = csum.at(i - 1) + dp.at(i);
    }
    cout << dp.at(S).val() << endl;
    return 0;
}