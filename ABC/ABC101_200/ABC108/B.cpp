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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    ll x3 = x2 - dy;
    ll y3 = y2 + dx;
    ll x4 = x3 - dx;
    ll y4 = y3 - dy;
    
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}