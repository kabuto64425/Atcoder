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
    ll N, W;
    cin >> N >> W;
    vector<pair<ll, ll>> wv(N);
    for(pair<ll, ll> &elm : wv) {
        cin >> elm.first >> elm.second;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(100001, 0));
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 100000; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);
            if(j - wv.at(i - 1).first >= 0) {
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j - wv.at(i - 1).first) + wv.at(i - 1).second);
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i <= W; i++) {
        ans = max(ans, dp.at(N).at(i));
    }
    cout << ans << endl;
    return 0;
}