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
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    for(string &elm : a) {
        cin >> elm;
    }
    vector<vector<mint>> dp(H, vector<mint>(W, 0));
    dp.at(0).at(0) = 1;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(a.at(i).at(j) == '#') {
                dp.at(i).at(j) = 0;
                continue;
            }
            if(i >= 1) {
                dp.at(i).at(j) += dp.at(i - 1).at(j);
            }
            if(j >= 1) {
                dp.at(i).at(j) += dp.at(i).at(j - 1);
            }
        }
    }
    cout << dp.at(H - 1).at(W - 1).val() << endl;
    return 0;
}