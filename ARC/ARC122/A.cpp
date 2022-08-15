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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<vector<mint>> dp(110000, vector<mint>(2, 0));
    dp.at(0).at(0) = A.at(0);
    dp.at(0).at(1) = 0;

    mint plusFactor = 1;
    mint minusFactor = 1;

    for(ll i = 1; i < N; i++) {
        dp.at(i).at(0) = (dp.at(i - 1).at(0) + dp.at(i - 1).at(1) + A.at(i) * plusFactor);
        dp.at(i).at(1) = (dp.at(i - 1).at(0) - A.at(i) * minusFactor);
        
        mint prePlusFactor = plusFactor;
        plusFactor = prePlusFactor + minusFactor;
        minusFactor = prePlusFactor;
    }
    mint ans = dp.at(N - 1).at(0) + dp.at(N - 1).at(1);
    cout << ans.val() << endl;
    return 0;
}