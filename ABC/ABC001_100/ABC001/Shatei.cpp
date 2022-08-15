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
    ll m;
    cin >> m;
    if(m < 100) {
        cout << setfill('0') << right << setw(2) << 0 << endl;
    } else if(m <= 5000) {
        cout << setfill('0') << right << setw(2) << m / 100 << endl;
    } else if(m >= 6000 and m <= 30000) {
        cout << setfill('0') << right << setw(2) << m / 1000 + 50 << endl;
    } else if(m >= 35000 and m <= 70000) {
        cout << setfill('0') << right << setw(2) << ((m / 1000) - 30) / 5 + 80 << endl;
    } else if(m > 70000) {
        cout << setfill('0') << right << setw(2) << 89 << endl;
    }

    return 0;
}