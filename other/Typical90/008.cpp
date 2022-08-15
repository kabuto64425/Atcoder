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
    const string atcoder = "atcoder";
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<mint>> dp(8, vector<mint>(N + 1, 0));
    
    for(ll i = 0; i <= N; i++) {
        dp.at(0).at(i) = 1;
    }
    
    for(ll i = 1; i <= 7; i++) {
        for(ll j = 1; j <= N; j++) {
            dp.at(i).at(j) += dp.at(i).at(j - 1);
            if(S.at(j - 1) == atcoder.at(i - 1)) {
                dp.at(i).at(j) += dp.at(i - 1).at(j - 1);
            }
        }
    }

    cout << dp.at(7).at(N).val() << endl;
    return 0;
}