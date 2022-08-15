#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, L;
    cin >> N >> L;
    if(L >= 0) {
        cout << (2 * L + N - 1) * N / 2 - L << endl;
    } else if(L + N -1 >= 0) {
        cout << (2 * L + N - 1) * N / 2 << endl;
    } else {
        cout << (2 * L + N - 1) * N / 2 - (L + N - 1) << endl;
    }
    return 0;
}