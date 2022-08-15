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
    ll T;
    cin >> T;
    for(ll t = 0; t < T; t++) {
        ll N;
        cin >> N;
        ll left = 1;
        ll right = N + 1;
        ll ans = 0;
        for(ll c = 0; c < 20; c++) {
            ll c1 = (left + left + right) / 3;
            ll c2 = (left + right + right) / 3;
            cout << "? " << c1 << endl;
            ll x; cin >> x;
            cout << "? " << c2 << endl;
            ll y; cin >> y;
            if(x > y) {
                right = c2;
            } else {
                left = c1;
            }
            ans = max({ans, x, y});
        }
        cout << "! " << ans << endl;
    }
    return 0;
}