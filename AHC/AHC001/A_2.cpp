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
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> xyr(n);
    for(auto &elm : xyr) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }

    vector<tuple<ll, ll, ll, ll>> abcd(n);
    for(auto &elm : abcd) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm) >> get<3>(elm);
    }

    long double score = 0;
    for(ll i = 0; i < n; i++) {
        tuple<ll, ll, ll> elmXyr = xyr.at(i);
        tuple<ll, ll, ll, ll> elmAbcd = abcd.at(i);
        if(get<0>(elmAbcd) > get<0>(elmXyr) or get<2>(elmAbcd) <= get<0>(elmXyr) or get<1>(elmAbcd) > get<1>(elmXyr) or get<3>(elmAbcd) <= get<1>(elmXyr)) {
            continue;
        }
        ll s = abs(get<2>(elmAbcd) - get<0>(elmAbcd)) * abs(get<3>(elmAbcd) - get<1>(elmAbcd));
        ll r = get<2>(elmXyr);
        long double p = 1 - (1 - min(r, s) / (long double) max(r, s)) * (1 - min(r, s) / (long double) max(r, s));
        score += p;
    }
    score *= 1000000000;
    score /= n;
    cout << (long long)score << endl;
    return 0;
}