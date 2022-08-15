#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> L(K), R(K);
    for(ll i = 0; i < K; i++) {
        cin >> L.at(i) >> R.at(i);
    }
    
    vector<mint> dp(220000);
    vector<mint> sum(220000);
    dp.at(1) = 1;
    sum.at(1) = dp.at(1);
    for(ll i = 2; i <= 200000; i++) {
        for(ll j = 0; j < K; j++) {
            R.at(j);
            L.at(j) - 1;
            if(i - L.at(j) >= 1) {
                dp.at(i) += sum.at(i - L.at(j));
            }
            if(i - R.at(j) - 1 >= 1) {
                dp.at(i) -= sum.at(i - R.at(j) - 1);
            }
        }
        sum.at(i) = sum.at(i - 1) + dp.at(i);
    }
    cout << dp.at(N).val() << endl;
    return 0;
}