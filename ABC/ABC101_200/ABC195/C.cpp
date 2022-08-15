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
    ll ans = 0;
    if(N <= 999) {
        cout << ans << endl;
        return 0;
    }
    if(N <= 999999) {
        cout << N - 999 << endl;
        return 0;
    }
    if(N <= 999999999) {
        cout << (N - 999999) * 2 + (999999 - 999) << endl;
        return 0;
    }
    if(N <= 999999999999) {
        cout << (N - 999999999) * 3 + (999999999 - 999999) * 2 + (999999 - 999) << endl;
        return 0;
    }
    if(N <= 999999999999999) {
        cout << (N - 999999999999) * 4 + (999999999999 - 999999999) * 3 + (999999999 - 999999) * 2 + (999999 - 999) << endl;
        return 0;
    }
    cout << (N - 999999999999999) * 5 + (999999999999999 - 999999999999) * 4 + (999999999999 - 999999999) * 3 + (999999999 - 999999) * 2 + (999999 - 999) << endl;
    return 0;
}
