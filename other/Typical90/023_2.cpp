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

    vector<vector<mint>> dp(25, vector<mint>(1 << 11));
    dp.at(0).at(0) = 1;

    for(ll i = 0; i < H; i++) {
        for(ll bit1 = 0; bit1 < (1 << W); bit1++) {
            for(ll bit2 = 0; bit2 < (1 << W); bit2++) {
                vector<vector<ll>> kings(2, vector<ll>(10));
                for(ll j = 0; j < W; j++) {
                    kings.at(0).at(j) = (bit1 / (1 << j)) % 2;
                }
                for(ll j = 0; j < W; j++) {
                    kings.at(1).at(j) = (bit2 / (1 << j)) % 2;
                }
                bool flag = true;
                for(ll j = 0; j < W; j++) {
                    if(kings.at(0).at(j) == 1 and kings.at(1).at(j)) {
                        flag = false;
                    }
                    if(j < W - 1 and kings.at(0).at(j) == 1 and kings.at(0).at(j + 1) == 1) {
                        flag = false;
                    }
                    if(j < W - 1 and kings.at(1).at(j) == 1 and kings.at(1).at(j + 1) == 1) {
                        flag = false;
                    }
                    if(j < W - 1 and kings.at(0).at(j) == 1 and kings.at(1).at(j + 1) == 1) {
                        flag = false;
                    }
                    if(j < W - 1 and kings.at(1).at(j) == 1 and kings.at(0).at(j + 1) == 1) {
                        flag = false;
                    }
                    if(i >= 1 and kings.at(0).at(j) == 1 and C.at(i - 1).at(j) == '#') {
                        flag = false;
                    }
                    if(kings.at(1).at(j) == 1 and C.at(i).at(j) == '#') {
                        flag = false;
                    }
                }
                if(flag) {
                    dp.at(i + 1).at(bit2) += dp.at(i).at(bit1);
                }
            }
        }
    }

    mint ans = 0;
    for(ll bit = 0; bit < (1 << W); bit++) {
        ans += dp.at(H).at(bit);
    }
    cout << ans.val() << endl;
    return 0;
}