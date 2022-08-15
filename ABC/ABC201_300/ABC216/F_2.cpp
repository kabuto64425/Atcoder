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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> AB(N);
    for(ll i = 0; i < N; i++) {
        cin >> AB.at(i).first;
    }
    for(ll i = 0; i < N; i++) {
        cin >> AB.at(i).second;
    }
    sort(ALL(AB));
    ll ans = 0;
    ll d = 1;
    vector<vector<bool>> dp(N + 1, vector<bool>(5500, 0));
    dp.at(0).at(0) = true;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 5000; j++) {
            dp.at(i).at(j) = dp.at(i).at(j) | dp.at(i - 1).at(j);
            if(j - AB.at(i - 1).second >= 0) {
                dp.at(i).at(j) = dp.at(i).at(j) | dp.at(i - 1).at(j - AB.at(i - 1).second);
            }
        }
        vector<ll> csum(5500, 0);
        for(ll j = 0; j <= 5000; j++) {
            if(dp.at(i).at(j)) {
                csum.at(j) = 1;
            }
        }
        for(ll j = 1; j <= 5000; j++) {
            csum.at(j) += csum.at(j - 1);
        }
        ans += (csum.at(AB.at(i - 1).first) - 1) * d;
        d *= 2;
    }
    cout << ans << endl;
    return 0;
}