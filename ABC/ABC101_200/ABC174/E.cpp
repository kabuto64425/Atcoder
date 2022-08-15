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

bool solve(const ll mid, const ll K, const vector<ll> &A) {
    ll count = 0;
    for(const ll &a : A) {
        count += ((a + (mid - 1)) / mid - 1);
    }
    if(count > K) {
        return false;
    }
    return true;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);

    ll m = 0;

    for(ll &a : A) {
        cin >> a;
        m = max(m, a);
    }

    ll ok = m;
    ll ng = 0;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(mid, K, A)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}