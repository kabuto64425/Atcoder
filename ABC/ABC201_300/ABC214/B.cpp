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
    ll S, T;
    cin >> S >> T;
    ll ans = 0;
    for(ll a = 0; a <= 100; a++) {
        for(ll b = 0; b <= 100; b++) {
            for(ll c = 0; c <= 100; c++) {
                if(a + b + c <= S and a * b * c <= T) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}