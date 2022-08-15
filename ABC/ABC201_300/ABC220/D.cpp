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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<vector<mint>> dp(N, vector<mint>(10, 0));
    dp.at(0).at(A.at(0)) = 1;
    for(ll i = 1; i < N; i++) {
        for(ll j = 0; j < 10; j++) {
            ll x = (j + A.at(i)) % 10;
            ll y = (j * A.at(i)) % 10;
            dp.at(i).at(x) += dp.at(i - 1).at(j);
            dp.at(i).at(y) += dp.at(i - 1).at(j);
        }
    }
    for(ll i = 0; i < 10; i++) {
        cout << dp.at(N - 1).at(i).val() << endl;
    }
    return 0;
}