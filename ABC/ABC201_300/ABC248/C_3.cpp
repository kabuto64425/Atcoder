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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vector<mint>> dp(N + 1, vector<mint>(3000, 0));
    dp.at(0).at(0) = 1;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j <= 2500; j++) {
            for(ll k = 1; k <= M; k++) {
                if(j + k > 2500) {
                    break;
                }
                dp.at(i + 1).at(j + k) += dp.at(i).at(j);
            }
        }
    }
    mint ans = 0;
    for(ll i = 0; i <= K; i++) {
        ans += dp.at(N).at(i);
    }
    cout << ans.val() << endl;
    return 0;
}