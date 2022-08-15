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
    ll N;
    cin >> N;
    vector<long double> p(N);
    for(long double &elm : p) {
        cin >> elm;
    }
    vector<vector<long double>> dp(N + 1, vector<long double>(N + 1, 0));
    dp.at(0).at(0) = 1;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= N - 1; j++) {
            dp.at(i).at(j) += dp.at(i - 1).at(j) * (1 - p.at(i - 1));
            dp.at(i).at(j + 1) += dp.at(i - 1).at(j) * p.at(i - 1);
        }
    }
    long double ans = 0;
    for(ll i = (N + 1) / 2; i <= N; i++) {
        ans += dp.at(N).at(i);
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}