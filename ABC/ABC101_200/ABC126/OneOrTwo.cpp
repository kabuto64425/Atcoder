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

int main(){
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll>> XYZ(M);
    for(tuple<ll, ll, ll> &xyz : XYZ) {
        cin >> get<0>(xyz) >> get<1>(xyz) >> get<2>(xyz);
        get<0>(xyz)--;
        get<1>(xyz)--;
    }
    dsu d(N);
    REP(i, M) {
        d.merge(get<0>(XYZ.at(i)), get<1>(XYZ.at(i)));
    }
    ll ans = 0;
    vector<bool> vec(110000, false);
    REP(i, N) {
        if(!vec.at(d.leader(i))) {
            ans++;
            vec.at(d.leader(i)) = true;
        }
    }
    cout << ans << endl;
    return 0;
}