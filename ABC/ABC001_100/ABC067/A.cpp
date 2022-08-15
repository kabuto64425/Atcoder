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
    ll A, B;
    cin >> A >> B;
    if(A % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    }
    if(B % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    }
    if((A + B) % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}