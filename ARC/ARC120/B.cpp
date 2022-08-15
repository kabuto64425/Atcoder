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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(string &s : S) {
        cin >> s;
    }
    vector<vector<ll>> vec(H + W + 1, vector<ll>(3, 0));
    for(ll i = 1; i <= H; i++) {
        for(ll j = 1; j <= W; j++) {
            char c = S.at(i - 1).at(j - 1);
            if(c == 'R') {
                vec.at(i + j).at(0)++;
            } else if(c == 'B') {
                vec.at(i + j).at(1)++;
            } else if(c == '.') {
                vec.at(i + j).at(2)++;
            }
        }
    }

    mint ans = 1;

    for(ll k = 2; k <= H + W; k++) {
        if(vec.at(k).at(0) >= 1 and vec.at(k).at(1) >= 1) {
            ans *= 0;
        } else if(vec.at(k).at(0) == 0 and vec.at(k).at(1) == 0 and vec.at(k).at(2) >= 1) {
            ans *= 2;
        }
    }
    cout << ans.val() << endl;
    return 0;
}