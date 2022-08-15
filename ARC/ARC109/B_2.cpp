#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

bool solve(ll X, ll mid) {
    if(mid > 0 and (mid + 1) / 2 > 1000000000000000001 / mid) {
        return false;
    }
    if(X >= mid * (mid + 1) / 2) {
        return true;
    }
    return false;
}

int main(){
    ll N;
    cin >> N;
    ll ok = 1;
    ll ng = N + 1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(N + 1, mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << N - ok + 1 << endl;
    return 0;
}