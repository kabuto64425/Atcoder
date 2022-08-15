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
    ll A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    if(A1 <= A2 and A2 <= A3) {
        cout << A3 - A1 << endl;
        return 0;
    }
    if(A1 <= A3 and A3 <= A2) {
        cout << A2 - A1 << endl;
        return 0;
    }
    if(A2 <= A1 and A1 <= A3) {
        cout << A3 - A2 << endl;
        return 0;
    }
    if(A2 <= A3 and A3 <= A1) {
        cout << A1 - A2 << endl;
        return 0;
    }
    if(A3 <= A1 and A1 <= A2) {
        cout << A2 - A3 << endl;
        return 0;
    }
    if(A3 <= A2 and A2 <= A1) {
        cout << A1 - A3 << endl;
        return 0;
    }
    return 0;
}