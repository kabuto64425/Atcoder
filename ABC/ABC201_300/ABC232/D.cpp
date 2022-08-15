#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    vector<string> C(H);
    for(ll i = 0; i < H; i++) {
        cin >> C.at(i);
    }
    vector<vector<bool>> dp(H, vector<bool>(W, false));
    dp.at(0).at(0) = true;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(C.at(i).at(j) == '#') {
                continue;
            }
            if(i >= 1) {
                dp.at(i).at(j) = dp.at(i).at(j) | dp.at(i - 1).at(j);
            }
            if(j >= 1) {
                dp.at(i).at(j) = dp.at(i).at(j) | dp.at(i).at(j - 1);
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(dp.at(i).at(j)) {
                ans = max(ans, (i + 1) + (j + 1) - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}