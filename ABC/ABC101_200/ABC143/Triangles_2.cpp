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
    vector<ll> L(N);
    for(ll &l : L) {
        cin >> l;
    }
    sort(L.begin(), L.end());
    ll ans = 0;
    for(ll i = 0; i < N - 2; i++) {
        for(ll j = i + 1; j < N - 1; j++) {
            ll lower = lower_bound(L.begin(), L.end(), L.at(i) + L.at(j)) - L.begin();
            ans += (lower - (j + 1));
        }
    }
    cout << ans << endl;
    return 0;
}