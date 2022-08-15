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
    vector<tuple<ll, ll, ll>> APX(N);
    for(tuple<ll, ll, ll> &t : APX) {
        cin >> get<0>(t) >> get<1>(t) >> get<2>(t);
    }
    ll ans = INF;
    for(tuple<ll, ll, ll> &t : APX) {
        if(get<2>(t) > get<0>(t)) {
            ans = min(ans, get<1>(t));
        }
    }
    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}