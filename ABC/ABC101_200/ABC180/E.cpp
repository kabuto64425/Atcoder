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

ll culcCost(tuple<ll, ll, ll> xyz1, tuple<ll, ll, ll> xyz2) {
    return abs(get<0>(xyz2) - get<0>(xyz1)) + abs(get<1>(xyz2) - get<1>(xyz1)) + max(0LL, get<2>(xyz2) - get<2>(xyz1));
}

int main(){
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> XYZ(N + 1);
    for(ll i = 1; i <= N; i++) {
        tuple<ll, ll, ll> &xyz = XYZ.at(i);
        cin >> get<0>(xyz) >> get<1>(xyz) >> get<2>(xyz);
    }

    vector<vector<ll>> dp(1 << 18, vector<ll>(20, INF));
    dp.at(0).at(1) = 0;

    for(ll bit = 0; bit < (1 << N); bit++){
        // 更新処理
        for(ll v = 1; v <= N; v++) {
            for(ll u = 1; u <= N; u++) {
                if(bit != 0 and (bit & (1 << (u - 1))) == 0) {
                    continue;
                }
                if((bit & (1 << (v - 1))) == 0) {
                    if(v != u) {
                        dp.at(bit | (1 << (v - 1))).at(v) = min(dp.at(bit | (1 << (v - 1))).at(v), dp.at(bit).at(u) + culcCost(XYZ.at(u), XYZ.at(v)));
                    }
                }
            }
        }
    }

    cout << dp.at((1 << N) - 1).at(1) << endl;

    return 0;
}