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
    ll x1, x2, x3;
    ll y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    if(x1 == x2) {
        cout << x3;
    } else if(x1 == x3) {
        cout << x2;
    } else {
        cout << x1;
    }
    cout << " ";
    if(y1 == y2) {
        cout << y3;
    } else if(y1 == y3) {
        cout << y2;
    } else {
        cout << y1;
    }
    cout << endl;
    return 0;
}