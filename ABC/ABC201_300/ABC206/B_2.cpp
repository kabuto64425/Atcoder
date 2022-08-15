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
    ll N;
    cin >> N;
    ll ok = 0;
    ll ng = 1000000001;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll price = mid * (mid + 1) / 2;
        if(price >= N) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    cout << ok + 1 << endl;
    return 0;
}