#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

long double combination(ll n, ll r) {
    long double ret = 1;
    for(ll i = 1; i <= r; i++) {
        ret = ret * (n - r + i);
        ret = ret / i;
    }
    return ret;
}

int main(){
    ll L;
    cin >> L;
    cout << (long long)combination(L - 1, L - 12) << endl;
    return 0;
}