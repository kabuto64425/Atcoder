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
    vector<vector<mint>> dp(N + 1, vector<mint>(5500));
    vector<vector<mint>> sum(N + 1, vector<mint>(5500));
    for(ll i = 1; i <= M; i++) {
        dp.at(1).at(i) += 1;
    }
    for(ll i = 1; i<= 5000; i++) {
        sum.at(1).at(i) = sum.at(1).at(i - 1) + dp.at(1).at(i);
    }

    for(ll i = 2; i <= N; i++) {
        for(ll j = 1; j <= M; j++) {
            if(j + K - 1 <= M) {
                dp.at(i).at(j) += sum.at(i - 1).at(M) - sum.at(i - 1).at(j + K - 1);
            }
            if(j - K >= 0) {
                dp.at(i).at(j) += sum.at(i - 1).at(j - K) - sum.at(i - 1).at(0);
            }
            if(K == 0) {
                dp.at(i).at(j) -= dp.at(i - 1).at(j);
            }
        }
        for(ll j = 1; j <= 5000; j++) {
            sum.at(i).at(j) = sum.at(i).at(j - 1) + dp.at(i).at(j);
        }
    }

    mint ans = 0;
    for(ll i = 1; i <= M; i ++) {
        ans += dp.at(N).at(i);
    }
    cout << ans.val() << endl;
}