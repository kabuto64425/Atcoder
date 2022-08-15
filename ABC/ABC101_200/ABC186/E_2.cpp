#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
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

int main(){
    ll T;
    cin >> T;
    vector<ll> N(T), S(T), K(T);
    for(ll i = 0; i < T; i++) {
        cin >> N.at(i) >> S.at(i) >> K.at(i);
    }
    for(ll t = 0; t < T; t++) {
        ll a = K.at(t);
        ll b = N.at(t) - S.at(t);
        ll m = N.at(t);
        ll g = gcd(a, m);
        if(b % g != 0) {
            cout << -1 << endl;
            continue;
        }
        a /= g;
        b /= g;
        m /= g;
        ll ainv = modinv(a, m);
        cout << (b * ainv) % m << endl;
    }
    return 0;
}