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
    ll A, B;
    cin >> A >> B;
    if((A + B) % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ll K = (A + B) / 2;
    if(A >= K and B >= K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if(A < K and B < K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << K << endl;
    return 0;
}