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
    vector<string> S(H);
    for(ll i = 0; i < H; i++) {
        cin >> S.at(i);
    }
    ll ans = 0;
    for(ll i = 1; i < H; i++) {
        for(ll j = 1; j < W; j++) {
            ll black = 0;
            if(S.at(i - 1).at(j - 1) == '#') {
                black++;
            }
            if(S.at(i - 1).at(j) == '#') {
                black++;
            }
            if(S.at(i).at(j - 1) == '#') {
                black++;
            }
            if(S.at(i).at(j) == '#') {
                black++;
            }
            if(black == 1 or black == 3) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}