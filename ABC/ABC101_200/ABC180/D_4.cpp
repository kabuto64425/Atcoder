#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll X, Y, A, B;
    cin >> X >> Y >> A >> B;
    ll e = 0;
    ll s = X;
    while(s <= 1e18 / A and s * A <= s + B and s * A < Y) {
        s *= A;
        e++;
    }
    e += (Y - s - 1) / B;
    cout << e << endl;
    return 0;
}