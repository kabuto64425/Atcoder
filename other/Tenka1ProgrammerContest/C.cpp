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
    ll N;
    cin >> N;
    for(ll h = 1; h <= 3500; h++) {
        for(ll n = 1; n <= 3500; n++) {
            ll x = N * h * n;
            ll y = 4 * h * n - N * n - N * h;
            if(y <= 0) {
                continue;
            }
            if(x % y != 0) {
                continue;
            }
            cout << n << " " << h << " " << x / y << endl;
            return 0;
        }
    }
    return 0;
}