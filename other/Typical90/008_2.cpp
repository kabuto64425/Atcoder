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
#define ALL(x) x.begin(),x.end()

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<mint>> dp(N + 1, vector<mint>(8));
    
    const string target = "atcoder";

    dp.at(0).at(0) = 1;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j <= 7; j++) {
            dp.at(i + 1).at(j) += dp.at(i).at(j);
            if(j < 7 and S.at(i) == target.at(j)) {
                dp.at(i + 1).at(j + 1) += dp.at(i).at(j);
            }
        }
    }
    cout << dp.at(N).at(7).val() << endl;
    return 0;
}