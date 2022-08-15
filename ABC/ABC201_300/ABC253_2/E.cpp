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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vector<mint>> dp(N + 1, vector<mint>(5500, 0));
    vector<vector<mint>> csum(N + 1, vector<mint>(5500, 0));
    for(ll j = 1; j <= M; j++) {
        dp.at(1).at(j) = 1;
    }
    csum.at(0).at(0) = 1;
    for(ll j = 0; j <= M; j++) {
        csum.at(1).at(j + 1) += csum.at(1).at(j) + dp.at(1).at(j + 1);
    }
    for(ll i = 1; i < N; i++) {
        for(ll j = 1; j <= M; j++) {
            if(j - K >= 0) {
                dp.at(i + 1).at(j) += (csum.at(i).at(j - K) - csum.at(i).at(0));
            }
            if(j + K <= M) {
                dp.at(i + 1).at(j) += (csum.at(i).at(M) - csum.at(i).at(j + K - 1));
            }
            if(K == 0) {
                dp.at(i + 1).at(j) -= dp.at(i).at(j);
            }
        }
        for(ll j = 0; j <= M; j++) {
            csum.at(i + 1).at(j + 1) += csum.at(i + 1).at(j) + dp.at(i + 1).at(j + 1);
        }
    }
    mint ans = 0;
    for(ll j = 0; j <= M; j++) {
        ans += dp.at(N).at(j);
    }
    cout << ans.val() << endl;
    return 0;
}