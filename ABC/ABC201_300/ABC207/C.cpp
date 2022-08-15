#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> tlr(N);
    for(tuple<ll, ll, ll> &elm : tlr) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }
    ll ans = 0;
    for(ll i = 0; i <= N - 2; i++) {
        for(ll j = i + 1; j <= N - 1; j++) {
            tuple<ll, ll, ll> elm1 = tlr.at(i);
            tuple<ll, ll, ll> elm2 = tlr.at(j);
            if((get<0>(elm1) == 1 or get<0>(elm1) == 2) and (get<0>(elm2) == 1 or get<0>(elm2) == 3)) {
                if(get<1>(elm1) > get<2>(elm2)) {
                    continue;
                }
            } else {
                if(get<1>(elm1) >= get<2>(elm2)) {
                    continue;
                }
            }

            if((get<0>(elm2) == 1 or get<0>(elm2) == 2) and (get<0>(elm1) == 1 or get<0>(elm1) == 3)) {
                if(get<1>(elm2) > get<2>(elm1)) {
                    continue;
                }
            } else {
                if(get<1>(elm2) >= get<2>(elm1)) {
                    continue;
                }
            }
            
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}