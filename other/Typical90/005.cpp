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

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, B, K;
    cin >> N >> B >> K;
    vector<ll> c(K);
    for(ll &elm : c) {
        cin >> elm;
    }
    vector<vector<mint>> dp(N + 1, vector<mint>(B, 0));
    dp.at(0).at(0) = 1; 
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j < B; j++) {
            for(ll k = 0; k < K; k++) {
                ll mod = (j * 10 + c.at(k)) % B;
                dp.at(i).at(mod) += dp.at(i - 1).at(j);
            }
        }
    }
    cout << dp.at(N).at(0).val() << endl;
    return 0;
}