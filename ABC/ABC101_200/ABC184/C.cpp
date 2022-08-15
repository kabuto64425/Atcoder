#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll r1, c1;
    cin >> r1 >> c1;
    ll r2, c2;
    cin >> r2 >> c2;
    // 0
    if(r1 == r2 and c1 == c2) {
        cout << 0 << endl;
        return 0;
    }
    // 1
    if(r1 + c1 == r2 + c2) {
        cout << 1 << endl;
        return 0;
    }
    if(r1 - c1 == r2 - c2) {
        cout << 1 << endl;
        return 0;
    }
    if(abs(r1 - r2) + abs(c1 - c2) <= 3) {
        cout << 1 << endl;
        return 0;
    }
    // 2
    if((abs(r1 - r2) + abs(c1 - c2)) % 2 == 0) {
        cout << 2 << endl;
        return 0;
    }
    if((abs(r1 - r2) + abs(c1 - c2)) <= 6) {
        cout << 2 << endl;
        return 0;
    }
    if(abs((r1 + c1) - (r2 + c2)) <= 3) {
        cout << 2 << endl;
        return 0;
    }
    if(abs((r1 - c1) - (r2 - c2)) <= 3) {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
    return 0;
}