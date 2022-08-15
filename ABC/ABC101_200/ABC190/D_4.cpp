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
    ll X = 2 * N;
    vector<ll> v;
    for(ll i = 1; i * i <= X; i++) {
        if(X % i == 0) {
            v.push_back(i);
            v.push_back(X / i);
        }
    }
    ll ans = 0;
    for(const ll &elm : v) {
        ll y = X / elm;
        if((elm % 2 == 1 and y % 2 == 0) or (elm % 2 == 0 and y % 2 == 1)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}