#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll pow_made(ll r, ll n) {
    ll res = 1;
    REP(i, n) {
        res *= r;
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    mint ans = 0;
    for(ll i = 0; i < 60; i++) {
        ll zero = 0;
        ll one = 0;
        for(const ll &a : A) {
            if(a & (1LL << i)) {
                one++;
            } else {
                zero++;
            }
        }
        mint x = one * zero;
        x *= pow_made(2, i);
        ans += x;
    }
    cout << ans.val() << endl;
    return 0;
}