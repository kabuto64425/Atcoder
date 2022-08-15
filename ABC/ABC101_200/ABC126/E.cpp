#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
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
    for(ll i = 0; i < M; i++) {
        d.merge(get<0>(XYZ.at(i)), get<1>(XYZ.at(i)));
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(d.leader(i) == i) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}