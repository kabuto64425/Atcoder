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

ll countdig(ll n) {
    ll res = 0;
    while(n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

bool solve(ll mid, ll A, ll B, ll X) {
    ll price = mid * A + countdig(mid) * B;
    if(price <= X) {
        return true;
    }
    return false;
}

int main(){
    ll A, B, X;
    cin >> A >> B >> X;
    ll ok = 0;
    ll ng = 1000000001;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(mid, A, B, X)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}