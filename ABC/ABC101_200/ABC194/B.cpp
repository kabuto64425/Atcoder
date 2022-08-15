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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> AB(N);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    ll ans = INF;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            if(i == j) {
                ans = min(ans, AB.at(i).first + AB.at(i).second);
            } else {
                ans = min(ans, max(AB.at(i).first, AB.at(j).second));
            }
        }
    }
    cout << ans << endl;
    return 0;
}