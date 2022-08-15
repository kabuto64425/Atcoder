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
    ll N, D, H;
    cin >> N >> D >> H;
    vector<pair<ll, ll>> dh(N);
    for(pair<ll, ll> &elm : dh) {
        cin >> elm.first >> elm.second;
    }
    long double ans = 0.0;
    for(const pair<ll, ll> &elm : dh) {
        ans = max(ans, H - D * (H - elm.second) / (long double)(D - elm.first));
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}