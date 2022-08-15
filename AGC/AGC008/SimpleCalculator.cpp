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
    ll x, y;
    cin >> x >> y;
    if(x >= 0 and y >= 0) {
        if(y >= x) {
            cout << y - x << endl;
        } else {
            if(y == 0) {
                cout << x + 1 << endl;
            } else {
                cout << x - y + 2 << endl;
            }
        }
    } else if(x >= 0 and y < 0) {
        if(abs(y) >= x) {
            cout << abs(y) - x + 1 << endl;
        } else {
            cout << x - abs(y) + 1 << endl;
        }
    } else if(x < 0 and y >= 0) {
        if(y >= abs(x)) {
            cout << y - abs(x) + 1 << endl;
        } else {
            if(y == 0) {
                cout << abs(x) << endl;
            } else {
                cout << abs(x) - y + 1 << endl;
            }
        }
    } else {
        if(abs(y) > abs(x)) {
            cout << abs(y) - abs(x) + 2 << endl;
        } else {
            cout << abs(x) - abs(y) << endl;
        }
    }
    return 0;
}