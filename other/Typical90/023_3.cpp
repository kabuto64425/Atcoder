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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(string &c : C) {
        cin >> c;
    }

    vector<vector<vector<mint>>> dp(18, vector<vector<mint>>(18, vector<mint>(1 << 18)));
    dp.at(0).at(0).at(0) = 1;
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            ll n1 = i;
            ll n2 = j + 1;
            if (n2 == W) { 
                n1 += 1;
                n2 = 0;
            }
            for(ll bit = 0; bit < (1 << (W + 1)); bit++) {
                if (dp.at(i).at(j).at(bit) == 0) {
                    continue;
                };
                vector<ll> bits(25);
                for (ll l = 0; l <= W; l++) {
                    bits.at(l) = (bit / (1 << l)) % 2;
                }
                dp.at(n1).at(n2).at(bit >> 1) += dp.at(i).at(j).at(bit);
                bool flag = true;
                if (C.at(i).at(j) == '#') {
                    flag = false;
                }
                if (bits.at(0) == 1 && i >= 1 && j >= 1) {
                    flag = false;
                }
                if (bits.at(1) == 1 && i >= 1) {
                    flag = false;
                }
                if (bits.at(2) == 1 && i >= 1 && j <= W - 2) {
                    flag = false;
                }
                if (bits.at(W) == 1 && j >= 1) {
                    flag = false;
                }
                if (flag == true) {
                    dp.at(n1).at(n2).at((bit >> 1) + (1 << W)) += dp.at(i).at(j).at(bit);
                }
            }
        }
    }
    // Step #3. Get Answer
    mint ans = 0;
    for (ll i = 0; i < (1 << (W + 1)); i++){
        ans += dp[H][0][i];
    }
    cout << ans.val() << endl;
    return 0;
}