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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll count = 0;
    for(const ll &a : A) {
        if(a < 0) {
            count++;
        }
    }
    if(count % 2 == 0) {
        ll ans = 0;
        for(const ll &a : A) {
            ans += abs(a);
        }
        cout << ans << endl;
    } else {
        ll ans = 0;
        ll x = INF;
        for(const ll &a : A) {
            ans += abs(a);
            x = min(x, abs(a));
        }
        ans -= x * 2;
        cout << ans << endl;
    }
    return 0;
}