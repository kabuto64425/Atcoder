#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 100000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, W;
    cin >> N >> W;
    vector<pair<ll, ll>> wv(N);
    for(pair<ll, ll> &elm : wv) {
        cin >> elm.first >> elm.second;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(100001, INF));
    dp.at(0).at(0) = 0;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 100000; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);
            if(j - wv.at(i - 1).second >= 0) {
                dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i - 1).at(j - wv.at(i - 1).second) + wv.at(i - 1).first);
            }
        }
    }
    ll ans = 0;
    for(ll i = 100000; i >= 0; i--) {
        if(dp.at(N).at(i) <= W) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}