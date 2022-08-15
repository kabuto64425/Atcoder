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
    ll T;
    cin >> T;
    ll L, X, Y;
    cin >> L >> X >> Y;
    ll Q;
    cin >> Q;
    vector<ll> E(Q);
    for(ll &e : E) {
        cin >> e;
    }

    for(const ll &e : E) {
        long double rad = 2 * M_PI * e / T;
        long double y = -sinl(rad) * L / 2;
        long double z = (1 - cosl(rad)) * L / 2;
        long double length = sqrtl(X * X + abs(Y - y) * abs(Y - y));
        long double ans = atan2l(z, length);
        cout << fixed << setprecision(20) << ans * 180 / M_PI << endl;
    }

    return 0;
}