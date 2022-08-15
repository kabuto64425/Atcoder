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
    ll N, C;
    cin >> N >> C;
    vector<tuple<ll, ll, ll>> abc(N);
    for(tuple<ll, ll, ll> &elm : abc) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }
    vector<pair<ll, ll>> p(N * 2);
    for(ll i = 0; i < N; i++) {
        p.at(i * 2).first = get<0>(abc.at(i));
        p.at(i * 2).second = get<2>(abc.at(i));
        p.at(i * 2 + 1).first = get<1>(abc.at(i)) + 1;
        p.at(i * 2 + 1).second = -get<2>(abc.at(i));
    }

    vector<ll> pos;
    for(ll i = 0; i < N * 2; i++) {
        pos.push_back(p.at(i).first);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    vector<ll> dp(440000);
    for(ll i = 0; i < N * 2; i++) {
        ll j = lower_bound(pos.begin(), pos.end(), p.at(i).first) - pos.begin();
        dp.at(j) += p.at(i).second;
    }

    for(ll i = 1; i <= (ll)dp.size() - 1; i++) {
        dp.at(i) += dp.at(i - 1);
    }

    ll ans = 0;

    for(ll i = 1; i < (ll)pos.size(); i++) {
        ans += min(dp.at(i - 1), C) * (pos.at(i) - pos.at(i - 1));
    }
    
    cout << ans << endl;
    
    return 0;
}