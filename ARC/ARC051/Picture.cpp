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
    ll x1, y1, r;
    cin >> x1 >> y1 >> r;
    ll x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    
    bool red = false;
    if(x1 + r > x3) {
        red = true;
    }
    if(x1 - r < x2) {
        red = true;
    }
    if(y1 + r > y3) {
        red = true;
    }
    if(y1 - r < y2) {
        red = true;
    }
    
    bool blue = false;
    if((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) > r * r) {
        blue = true;
    }
    if((x2 - x1) * (x2 - x1) + (y3 - y1) * (y3 - y1) > r * r) {
        blue = true;
    }
    if((x3 - x1) * (x3 - x1) + (y2 - y1) * (y2 - y1) > r * r) {
        blue = true;
    }
    if((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) > r * r) {
        blue = true;
    }
    if(red) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    if(blue) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}