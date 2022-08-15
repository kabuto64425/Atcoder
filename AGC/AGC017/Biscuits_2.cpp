#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    ll kisu = 0;
    ll gusu = 0;
    for(const ll &a : A) {
        if(a % 2 == 0) {
            gusu++;
        } else {
            kisu++;
        }
    }
    if(P == 1 and kisu == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    if(P == 0) {
        for(ll i = 0; i <= kisu; i += 2) {
            ans += combination(kisu, i) * pow(2, gusu);
        }
    } else {
        for(ll i = 1; i <= kisu; i += 2) {
            ans += combination(kisu, i) * pow(2, gusu);
        }
    }
    cout << ans << endl;
    return 0;
}