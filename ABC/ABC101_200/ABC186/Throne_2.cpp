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

// x >= 0 で、1次合同方程式ax≡b (mod m)を満たす最小の整数xを返します。
// 存在しない場合、-1を返します。
// ※atcoderlibraryが必要です。
ll modularArithmetic(ll a, ll b, ll m) {
    ll d = gcd(a, m);
    if(b % d != 0) {
        return -1;
    }
    a /= d;
    m /= d;
    b /= d;
    modint::set_mod(m);
    modint res = modint(b) / a;
    return res.val();
}

int main(){
    ll T;
    cin >> T;
    REP(i, T) {
        ll N, S, K;
        cin >> N >> S >> K;
        cout << modularArithmetic(K, -S, N) << endl;
    }
    return 0;
}