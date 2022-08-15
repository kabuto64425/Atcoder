#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    vector<string> A(H);
    for(ll i = 0; i < H; i++) {
        cin >> A.at(i);
    }
    vector<vector<ll>> map(H + 1, vector<ll>(W + 1));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(A.at(i).at(j) == '+') {
                map.at(i + 1).at(j + 1) = 1;
            } else {
                map.at(i + 1).at(j + 1) = -1;
            }
        }
    }

    vector<vector<ll>> dp(H + 1, vector<ll>(W + 1));
    for(ll i = 1; i <= H; i++) {
        for(ll j = 1; j <= W; j++) {
            if((i + j) % 2 == 0) {
                dp.at(i).at(j) = -INF;
            } else {
                dp.at(i).at(j) = INF;
            }
        }
    }
    dp.at(H).at(W) = 0;
    for(ll i = H; i >= 1; i--) {
        for(ll j = W; j >= 1; j--) {
            if(i == H and j == W) {
                continue;
            }
            if((i + j) % 2 == 0) {
                if(i + 1 <= H) {
                    dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i + 1).at(j) + map.at(i + 1).at(j));
                }
                if(j + 1 <= W) {
                    dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i).at(j + 1) + map.at(i).at(j + 1));
                }
            } else {
                if(i + 1 <= H) {
                    dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i + 1).at(j) - map.at(i + 1).at(j));
                }
                if(j + 1 <= W) {
                    dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(j + 1) - map.at(i).at(j + 1));
                }
            }
        }
    }
    if(dp.at(1).at(1) > 0) {
        cout << "Takahashi" << endl;
        return 0;
    } else if(dp.at(1).at(1) == 0) {
        cout << "Draw" << endl;
        return 0;
    }
    cout << "Aoki" << endl;
    return 0;
}