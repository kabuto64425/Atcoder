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
        if(N == 1) {
            cout << "? " << 1 << endl;
            ll d1; cin >> d1;
            cout << "! " << d1 << endl;
            continue;
        }
        ll left = 1;
        ll right = N;
        ll ans = 0;
        for(ll c = 0; c < 11; c++) {
            ll mid = (left + right) / 2;
            cout << "? " << mid << endl;
            ll d1; cin >> d1;
            cout << "? " << mid + 1 << endl;
            ll d2; cin >> d2;
            if(d2 - d1 >= 0) {
                left = mid;
            } else {
                right = mid;
            }
            ans = max({ans, d1, d2});
        }
        cout << "! " << ans << endl;
    }
    return 0;
}