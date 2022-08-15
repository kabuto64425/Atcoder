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
    vector<ll> A(M), B(M), C(M);
    for(ll i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i) >> C.at(i);
    }
    dsu d(N);
    vector<tuple<ll, ll, ll>> edges(M);
    for(ll i = 0; i < M; i++) {
        edges.at(i) = {C.at(i), A.at(i) - 1, B.at(i) - 1};
    }
    sort(ALL(edges));
    ll ans = 0;
    for(ll i = 0; i < M; i++) {
        ll c = get<0>(edges.at(i));
        ll a = get<1>(edges.at(i));
        ll b = get<2>(edges.at(i));
        if(d.same(a, b)) {
            if(c >= 0) {
                ans += c;
            }
        } else {
            d.merge(a, b);
        }
    }
    cout << ans << endl;
    return 0;
}