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
    vector<pair<long double, long double>> lr(N);
    for(ll i = 0 ; i < N; i++) {
        tuple<ll, ll, ll> elm = tlr.at(i);
        if(get<0>(elm) == 1 or get<0>(elm) == 2) {
            lr.at(i).first = get<1>(elm);
        } else {
            lr.at(i).first = get<1>(elm) + 0.1;
        }

        if(get<0>(elm) == 1 or get<0>(elm) == 3) {
            lr.at(i).second = get<2>(elm);
        } else {
            lr.at(i).second = get<2>(elm) - 0.1;
        }
    }
    ll ans = 0;
    for(ll i = 0; i <= N - 2; i++) {
        for(ll j = i + 1; j <= N - 1; j++) {
            pair<long double, long double> elm1 = lr.at(i);
            pair<long double, long double> elm2 = lr.at(j);
            if(elm1.first <= elm2.second and elm2.first <= elm1.second) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}