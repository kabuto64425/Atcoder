#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> AB(N);
    REP(i, N) {
        cin >> AB.at(i).first >> AB.at(i).second;
    }
    ll ans = 0;
    REP(i, N) {
        ans += (AB.at(i).first + AB.at(i).second) * (AB.at(i).second - AB.at(i).first + 1) / 2;
    }
    cout << ans << endl;
}