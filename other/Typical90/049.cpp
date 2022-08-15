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
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll>> CLR(M);
    for(tuple<ll, ll, ll> &clr : CLR) {
        cin >> get<0>(clr) >> get<1>(clr) >> get<2>(clr);
    }
    sort(CLR.begin(), CLR.end());
    dsu d(N + 1);
    ll ans = 0;
    for(ll i = 0; i < M; i++) {
        ll l = get<1>(CLR.at(i)) - 1;
        ll r = get<2>(CLR.at(i));
        if(d.leader(l) != d.leader(r)) {
            ans += get<0>(CLR.at(i));
            d.merge(l, r);
        }
    }
    if(d.size(0) != N + 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}