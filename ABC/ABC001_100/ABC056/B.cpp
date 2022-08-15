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
    ll W, a, b;
    cin >> W >> a >> b;
    ll ans = INF;
    for(ll i = 1; i <= 100000; i++) {
        if(i + W >= a and i <= a + W) {
            ans = min(ans, abs(b - i));
        }
    }
    cout << ans << endl;
    return 0;
}