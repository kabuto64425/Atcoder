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

bool solve(ll t, ll N, ll mid) {
    ll pre = (mid * 100 + 100 + t - 1) / (100 + t);
    if(mid - pre <= N - 1) {
        return true;
    }
    return false;
}

int main(){
    ll t, N;
    cin >> t >> N;

    ll ok = 1;
    ll ng = 1000000000000000;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(t, N, mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}