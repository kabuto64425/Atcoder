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

void solve(ll N, ll S, ll K) {
    ll A, B, M;
    A = K;
    B = N - S;
    M = N;
    ll d = gcd(gcd(A, B), M);
    A = A / d;
    B = B / d;
    M = M / d;
    if(gcd(A, M) != 1) {
        cout << -1 << endl;
        return;
    }
    ll Ainv = modinv(A, M);
    cout << (B * Ainv) % M << endl;
    return;
}

int main(){
    ll T;
    cin >> T;
    REP(r, T) {
        ll N, S, K;
        cin >> N >> S >> K;
        solve(N, S, K);
    }
    return 0;
}