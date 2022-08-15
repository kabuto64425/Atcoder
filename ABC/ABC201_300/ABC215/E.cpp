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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(1024, vector<mint>(10, 0)));

    for(ll i = 1; i <= N; i++) {
        ll c = S.at(i - 1) - 'A';
        for(ll bit = 0; bit < (1 << 10); bit++) {
            for(ll j = 0; j < 10; j++) {
                dp.at(i).at(bit).at(j) += dp.at(i - 1).at(bit).at(j);
                if(j == c) {
                    dp.at(i).at(bit).at(j) += dp.at(i - 1).at(bit).at(j);
                }
            }
        }
        for(ll bit = 0; bit < (1 << 10); bit++) {
            if(!(bit & (1 << c))) {
                for(ll j = 0; j < 10; j++) {
                    dp.at(i).at(bit | (1 << c)).at(c) += dp.at(i - 1).at(bit).at(j);
                }
            }
        }
        dp.at(i).at(1 << c).at(c) += 1;
    }
    mint ans = 0;
    for(ll bit = 0; bit < (1 << 10); bit++) {
        for(ll j = 0; j < 10; j++) {
            ans += dp.at(N).at(bit).at(j);
        }
    }
    cout << ans.val() << endl;
    return 0;
}