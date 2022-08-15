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
    ll K, A, B;
    cin >> K >> A >> B;
    if(K < A + 1) {
        cout << K + 1 << endl;
        return 0;
    }
    if(B < A + 2) {
        cout << K + 1 << endl;
        return 0;
    }
    ll rest = K - (A + 1);
    cout << B + (B - A) * (rest / 2) + rest % 2 << endl;
    return 0;
}