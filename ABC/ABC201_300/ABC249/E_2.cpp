#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, P;
    cin >> N >> P;
    modint::set_mod(P);
    vector<vector<modint>> dp(5000, vector<modint>(5000, 0));
    dp.at(0).at(0) = 1;
    dp.at(0).at(1) = -1;
    for(ll i = 0; i <= N; i++) {
        for(ll j = 0; j < N; j++) {
            dp.at(i).at(j + 1) += dp.at(i).at(j);
        }
        ll c = 25;
        if(i == 0) {
            c = 26;
        }
        for(ll j = 0; j <= N; j++) {
            modint x = dp.at(i).at(j);
            dp.at(i + 2).at(j + 1) += c * x;
            dp.at(i + 2).at(j + 10) -= c * x;
            dp.at(i + 3).at(j + 10) += c * x;
            dp.at(i + 3).at(j + 100) -= c * x;
            dp.at(i + 4).at(j + 100) += c * x;
            dp.at(i + 4).at(j + 1000) -= c * x;
            dp.at(i + 5).at(j + 1000) += c * x;
        }
    }
    modint ans = 0;
    for(ll i = 0; i < N; i++) {
        ans += dp.at(i).at(N);
    }
    cout << ans.val() << endl;
    return 0;
}