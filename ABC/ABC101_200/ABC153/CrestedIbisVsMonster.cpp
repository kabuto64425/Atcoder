#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, N;
    cin >> H >> N;
    vector<pair<ll, ll>> AB(N);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    vector<ll> dp(10001, INF);
    dp.at(0) = 0;
    for(ll i = 1; i <= 10000; i++) {
        for(ll j = 0; j < N; j++) {
            if(i - AB.at(j).first >= 0) {
                dp.at(i) = min(dp.at(i), dp.at(i - AB.at(j).first) + AB.at(j).second);
            } else {
                dp.at(i) = min(dp.at(i), dp.at(0) + AB.at(j).second);
            }
        }
    }
    cout << dp.at(H) << endl;
    return 0;
}