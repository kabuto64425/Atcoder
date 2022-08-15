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
#define ALL(x) x.begin(),x.end()

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<vector<mint>> dp(K + 1, vector<mint>(4, 0));
    if(x1 == x2 and y1 == y2) {
        dp.at(0).at(3) = 1;
    } else if(y1 == y2) {
        dp.at(0).at(2) = 1;
    } else if(x1 == x2) {
        dp.at(0).at(1) = 1;
    } else {
        dp.at(0).at(0) = 1;
    }
    for(ll k = 0; k < K; k++) {
        dp.at(k + 1).at(0) = dp.at(k).at(0) * (H + W - 4) + dp.at(k).at(1) * (H - 1) + dp.at(k).at(2) * (W - 1);
        dp.at(k + 1).at(1) = dp.at(k).at(0) + dp.at(k).at(1) * (W - 2) + dp.at(k).at(3) * (W - 1);
        dp.at(k + 1).at(2) = dp.at(k).at(0) + dp.at(k).at(2) * (H - 2) + dp.at(k).at(3) * (H - 1);
        dp.at(k + 1).at(3) = dp.at(k).at(1) + dp.at(k).at(2);
    }
    cout << dp.at(K).at(3).val() << endl;
    return 0;
}