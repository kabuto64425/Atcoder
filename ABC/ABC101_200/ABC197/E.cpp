#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = LLONG_MAX;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> XC(N);
    for(pair<ll, ll> &xc : XC) {
        cin >> xc.first >> xc.second;
    }
    vector<pair<ll, ll>> lr(N + 1, {INF, -INF});
    for(const pair<ll, ll> &xc : XC) {
        lr.at(xc.second).first = min(lr.at(xc.second).first, xc.first);
        lr.at(xc.second).second = max(lr.at(xc.second).second, xc.first);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(2, INF));
    dp.at(0).at(0) = 0;
    dp.at(0).at(1) = 0;
    ll pl = 0;
    ll pr = 0;
    for(ll i = 1; i <= N; i++) {
        if(lr.at(i).first == INF and lr.at(i).second == -INF) {
            dp.at(i).at(0) = dp.at(i - 1).at(0);
            dp.at(i).at(1) = dp.at(i - 1).at(1);
        } else {
            dp.at(i).at(0) = min(dp.at(i).at(0), (dp.at(i - 1).at(0) + abs(pl - lr.at(i).second)) + (lr.at(i).second - lr.at(i).first));
            dp.at(i).at(0) = min(dp.at(i).at(0), (dp.at(i - 1).at(1) + abs(pr - lr.at(i).second)) + (lr.at(i).second - lr.at(i).first));

            dp.at(i).at(1) = min(dp.at(i).at(1), (dp.at(i - 1).at(0) + abs(pl - lr.at(i).first)) + (lr.at(i).second - lr.at(i).first));
            dp.at(i).at(1) = min(dp.at(i).at(1), (dp.at(i - 1).at(1) + abs(pr - lr.at(i).first)) + (lr.at(i).second - lr.at(i).first));

            pl = lr.at(i).first;
            pr = lr.at(i).second;
        }
    }
    cout << min(dp.at(N).at(0) + abs(pl), dp.at(N).at(1) + abs(pr)) << endl;
    return 0;
}