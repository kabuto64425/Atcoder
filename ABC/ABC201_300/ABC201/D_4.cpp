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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(ll i = 0; i < H; i++) {
        cin >> A.at(i);
    }
    vector<vector<ll>> dp(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if((i + j) % 2 == 0) {
                dp.at(i).at(j) = -INF;
            } else {
                dp.at(i).at(j) = INF;
            }
        }
    }
    dp.at(H - 1).at(W - 1) = 0;
    for(ll h = H - 1; h >= 0; h--) {
        for(ll w = W - 1; w >= 0; w--) {
            if(h == H - 1 and w == W - 1) {
                continue;
            }
            if((h + w) % 2 == 0) {
                if(h + 1 < H) {
                    chmax(dp.at(h).at(w), dp.at(h + 1).at(w) + ((A.at(h + 1).at(w) == '+')? 1 : -1));
                }
                if(w + 1 < W) {
                    chmax(dp.at(h).at(w), dp.at(h).at(w + 1) + ((A.at(h).at(w + 1) == '+')? 1 : -1));
                }
            } else {
                if(h + 1 < H) {
                    chmin(dp.at(h).at(w), dp.at(h + 1).at(w) + ((A.at(h + 1).at(w) == '+')? -1 : 1));
                }
                if(w + 1 < W) {
                    chmin(dp.at(h).at(w), dp.at(h).at(w + 1) + ((A.at(h).at(w + 1) == '+')? -1 : 1));
                }
            }
        }
    }
    if(dp.at(0).at(0) > 0) {
        cout << "Takahashi" << endl;
        return 0;
    } else if(dp.at(0).at(0) == 0) {
        cout << "Draw" << endl;
        return 0;
    } else {
        cout << "Aoki" << endl;
        return 0;
    }
    return 0;
}