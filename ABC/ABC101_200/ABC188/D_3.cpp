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
    ll N, C;
    cin >> N >> C;
    vector<tuple<ll, ll, ll>> abc(N);
    for(auto &elm : abc) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }
    vector<tuple<ll, ll, ll>> vec(2 * N);
    for(ll i = 0; i < N; i++) {
        get<0>(vec.at(i * 2)) = get<0>(abc.at(i));
        get<1>(vec.at(i * 2)) = get<2>(abc.at(i));
        get<0>(vec.at(i * 2 + 1)) = get<1>(abc.at(i)) + 1;
        get<1>(vec.at(i * 2 + 1)) = -get<2>(abc.at(i));
    }
    sort(vec.begin(), vec.end());
    for(ll i = 0; i < 2 * N; i++) {
        get<2>(vec.at(i)) = i + 1;
    }
    vector<ll> sum(440000, 0);
    for(ll i = 1; i <= 2 * N; i++) {
        sum.at(i) = get<1>(vec.at(i - 1));
    }
    for(ll i = 1; i <= 2 * N; i++) {
        sum.at(i) += sum.at(i - 1);
    }
    ll ans = 0;
    for(ll i = 1; i < 2 * N; i++) {
        ans += min(sum.at(i), C) * (get<0>(vec.at(i)) - get<0>(vec.at(i - 1)));
    }
    cout << ans << endl;
    return 0;
}