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
    ll A, B, W;
    cin >> A >> B >> W;
    ll target = W * 1000;
    ll minAns = (target + (B - 1))/ B;
    long double check1 = target / (long double) minAns;
    if(check1 < A) {
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }
    ll maxAns = target / A;
    ll mod = target % A;
    long double check2 = mod / (long double)maxAns;
    if(A + check2 > B) {
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }
    cout << minAns << " " << maxAns << endl;
    return 0;
}