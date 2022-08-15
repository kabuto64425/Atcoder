#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll combination(ll n, ll r) {
    ll ret = 1;
    for(ll i = 1; i <= r; i++) {
        ret *= (n - i + 1);
        ret /= i;
    }
    return ret;
}

int main(){
    ll N, P;
    cin >> N >> P;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll oddCount = 0;
    ll evenCount = 0;
    for(const ll &a : A) {
        if(a % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    ll ans = 1;

    REP(i, evenCount) {
        ans *= 2;
    }

    if(P % 2 == 0) {
        ll n = 0;
        for(ll i = 0; i <= oddCount; i += 2) {
            n += combination(oddCount, i);
        }
        ans *= n;
    } else {
        ll n = 0;
        for(ll i = 1; i <= oddCount; i += 2) {
            n += combination(oddCount, i);
        }
        ans *= n;
    }

    cout << ans << endl;

    return 0;
}