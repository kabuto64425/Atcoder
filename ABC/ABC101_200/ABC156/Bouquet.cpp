#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll combination(ll n, ll r) {
    ll res = 1;
    REP(i, r) {
        res *= (n - i);
        res %= MOD;
        res = res * modinv((i + 1), MOD) % MOD;
    }
    return res;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = mod_pow(2, n, MOD);
    ans -= 1;
    ans = (ans + MOD) % MOD;
    ans -= combination(n, a);
    ans = (ans + MOD) % MOD;
    ans -= combination(n, b);
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}