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

bool sort_by_second(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second == b.second) {
        a.first > b.first;
    }
    return a.second > b.second;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(N);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
    }

    sort(AB.begin(), AB.end(), sort_by_second);

    ll ans = 0;
    ll day = 0;

    for(ll i = 0; i < N; i++) {
        if(day + AB.at(i).first <= M) {
            ans += AB.at(i).second;
            day++;
        }
    }

    cout << ans << endl;
    return 0;
}