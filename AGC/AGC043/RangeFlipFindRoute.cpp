#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    for(string &elm : s) {
        cin >> elm;
    }
    vector<vector<ll>> dp(H + 1, vector<ll>(W + 1, INF));
    for(ll i = 1; i <= H; i++) {
        for(ll j = 1; j <= W; j++) {
            if(i == 1 and j == 1) {
                if(s.at(i - 1).at(j - 1) == '.') {
                    dp.at(i).at(j) = 0;
                } else {
                    dp.at(i).at(j) = 1;
                }
                continue;
            }
            if(s.at(i -1).at(j - 1) == '.') {
                dp.at(i).at(j) = min(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
            } else {
                ll up = dp.at(i - 1).at(j);
                if(i >= 2 and s.at(i - 2).at(j - 1) == '.') {
                    up++;
                }
                ll left = dp.at(i).at(j - 1);
                if(j >= 2 and s.at(i - 1).at(j - 2) == '.') {
                    left++;
                }
                dp.at(i).at(j) = min(up, left);
            }
        }
    }
    cout << dp.at(H).at(W) << endl;
    return 0;
}