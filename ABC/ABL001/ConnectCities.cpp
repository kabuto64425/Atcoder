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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(M);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
        ab.first--;
        ab.second--;
    }
    dsu d(N);
    REP(i, M) {
        d.merge(AB.at(i).first, AB.at(i).second);
    }
    ll ans = 0;
    vector<bool> vec(110000, false);
    REP(i, N) {
        if(!vec.at(d.leader(i))) {
            ans++;
            vec.at(d.leader(i)) = true;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}