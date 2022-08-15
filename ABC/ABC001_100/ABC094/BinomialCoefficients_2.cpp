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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &elm : a) {
        cin >> elm;
    }
    ll ma = *max_element(a.begin(), a.end());
    long double target = (long double)ma / 2;
    long double current = INF;
    ll ans;
    for(ll i = 0; i < n; i++) {
        if(ma == a[i]) {
            continue;
        }
        if(abs(a[i] - target) < current) {
            current = abs(a[i] - target);
            ans = a[i];
        }
    }
    cout << ma << " " << ans << endl;
    return 0;
}