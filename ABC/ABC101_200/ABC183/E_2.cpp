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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(ll i = 0; i < H; i++) {
        cin >> S.at(i);
    }
    vector<vector<mint>> dp(H, vector<mint>(W, 0));
    dp.at(0).at(0) = 1;
    vector<vector<mint>> X(H, vector<mint>(W, 0));
    vector<vector<mint>> Y(H, vector<mint>(W, 0));
    vector<vector<mint>> Z(H, vector<mint>(W, 0));
    X.at(0).at(0) = 0;
    Y.at(0).at(0) = 0;
    Y.at(0).at(0) = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(j) == '#') {
                continue;
            }
            if(i >= 1) {
                dp.at(i).at(j) += Y.at(i - 1).at(j);
            }
            if(j >= 1) {
                dp.at(i).at(j) += X.at(i).at(j - 1);
            }
            if(i >= 1 and j >= 1) {
                dp.at(i).at(j) += Z.at(i - 1).at(j - 1);
            }
            if(i >= 1) {
                Y.at(i).at(j) = Y.at(i - 1).at(j) + dp.at(i).at(j);
            } else {
                Y.at(i).at(j) = dp.at(i).at(j);
            }
            if(j >= 1) {
                X.at(i).at(j) = X.at(i).at(j - 1) + dp.at(i).at(j);
            } else {
                X.at(i).at(j) = dp.at(i).at(j);
            }
            if(i >= 1 and j >= 1) {
                Z.at(i).at(j) = Z.at(i - 1).at(j - 1) + dp.at(i).at(j);
            } else {
                Z.at(i).at(j) = dp.at(i).at(j);
            }
        }
    }
    cout << dp.at(H - 1).at(W - 1).val() << endl;
    return 0;
}