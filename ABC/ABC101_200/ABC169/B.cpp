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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll ans = 1;
    for(const ll &a : A) {
        if(a > 0 and ans > 1000000000000000000 / a) {
            ans = INF;
            continue;
        }
        ans *= a;
    }
    if(ans > 1000000000000000000) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}