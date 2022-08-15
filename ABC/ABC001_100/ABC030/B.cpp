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
    ll n, m;
    cin >> n >> m;
    n %= 12;
    long double d1 = (n * 30 + m * 0.5);
    long double d2 = (m * 6);
    cout << fixed << setprecision(20) << min(abs(d1 - d2), (long double)360 - abs(d1 - d2)) << endl;
    return 0;
}