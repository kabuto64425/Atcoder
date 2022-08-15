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
    ll H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<string> S(H);
    for(string &s : S) {
        cin >> s;
    }
    ll ans = 0;
    for(ll i = Y; i >= 1; i--) {
        if(S.at(X - 1).at(i - 1) == '#') {
            break;
        }
        ans++;
    }
    for(ll i = Y; i <= W; i++) {
        if(S.at(X - 1).at(i - 1) == '#') {
            break;
        }
        ans++;
    }
    for(ll i = X; i >= 1; i--) {
        if(S.at(i - 1).at(Y - 1) == '#') {
            break;
        }
        ans++;
    }
    for(ll i = X; i <= H; i++) {
        if(S.at(i - 1).at(Y - 1) == '#') {
            break;
        }
        ans++;
    }
    cout << ans - 3 << endl;
    return 0;
}