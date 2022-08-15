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

bool sort_by(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
    return get<2>(a) > get<2>(b);
}

int main(){
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> AB(N);
    for(auto &ab : AB) {
        cin >> get<0>(ab) >> get<1>(ab);
        get<2>(ab) = get<0>(ab) * 2 + get<1>(ab);
    }
    sort(AB.begin(), AB.end(), sort_by);
    ll aoki = 0;
    for(const auto &ab : AB) {
        aoki += get<0>(ab);
    }
    ll ans = 0;
    ll index = 0;
    ll takahashi = 0;
    while(takahashi <= aoki) {
        takahashi += get<2>(AB.at(index));
        ans++;
        index++;
    }
    cout << ans << endl;
    return 0;
}