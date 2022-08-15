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
    vector<tuple<ll, ll, ll>> CSF(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> get<0>(CSF.at(i)) >> get<1>(CSF.at(i)) >> get<2>(CSF.at(i));
    }
    for(ll i = 0; i <= N - 2; i++) {
        ll ans = get<0>(CSF.at(i)) + get<1>(CSF.at(i));
        for(ll j = i + 1; j <= N - 2; j++) {
            if(ans <= get<1>(CSF.at(j))) {
                ans = get<1>(CSF.at(j)) + get<0>(CSF.at(j));
            } else {
                ll x = ans - get<1>(CSF.at(j));
                ll y = (x + (get<2>(CSF.at(j)) - 1)) / get<2>(CSF.at(j));
                ans = get<1>(CSF.at(j)) + y * get<2>(CSF.at(j)) + get<0>(CSF.at(j));
            }
        }
        cout << ans << endl;
    }
    cout << 0 << endl;
    return 0;
}