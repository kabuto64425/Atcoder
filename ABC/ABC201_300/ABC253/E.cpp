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
    if(K == 0) {
        mint ans = 1;
        for(ll i = 0; i < N; i++) {
            ans *= M;
        }
        cout << ans.val() << endl;
        return 0;
    }
    vector<vector<mint>> dp(1100, vector<mint>(5500, 0));
    vector<vector<mint>> sum(1100, vector<mint>(5500, 0));
    
    for(ll i = 1; i <= M; i++) {
        dp.at(1).at(i) += 1;
    }
    for(ll i = 1; i <= M; i++) {
        sum.at(1).at(i) += sum.at(1).at(i - 1) + dp.at(1).at(i);
    }

    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= M; j++) {
            // j : 前の値
            if(j + K <= M) {
                dp.at(i + 1).at(j) += (sum.at(i).at(M) - sum.at(i).at(j + K - 1));
            }
            if(j - K >= 1) {
                dp.at(i + 1).at(j) += (sum.at(i).at(j - K) - sum.at(i).at(0));
            }
        }
        for(ll j = 1; j <= M; j++) {
            sum.at(i + 1).at(j) += sum.at(i + 1).at(j - 1) + dp.at(i + 1).at(j);
        }
    }

    mint ans = 0;
    for(ll i = 1; i <= M; i++) {
        ans += dp.at(N).at(i);
    }

    cout << ans.val() << endl;
    
    return 0;
}