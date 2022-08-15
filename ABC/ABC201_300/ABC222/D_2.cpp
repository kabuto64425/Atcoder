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
    vector<ll> a(N), b(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> b.at(i);
    }
    vector<vector<mint>> dp(3001, vector<mint>(3001, 0));
    dp.at(0).at(0) = 1;
    for(ll i = 1; i <= 3000; i++) {
        dp.at(0).at(i) += dp.at(0).at(i - 1);
    }
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 3000; j++) {
            if(j >= a.at(i - 1) and j <= b.at(i - 1)) {
                dp.at(i).at(j) += dp.at(i - 1).at(j);
            }
            if(j >= 1) {
                dp.at(i).at(j) += dp.at(i).at(j - 1);
            }
        }
    }
    cout << dp.at(N).at(b.at(N - 1)).val() << endl;
    return 0;
}