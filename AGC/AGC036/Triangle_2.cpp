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
    ll S;
    cin >> S;
    ll y = (S + 999999999) / 1000000000;
    ll x = (-(S % 1000000000) + 1000000000) % 1000000000;
    cout << 0 << " " << 0 << " " << 1000000000 << " " << 1 << " " << x << " " << y << endl;
    return 0;
}