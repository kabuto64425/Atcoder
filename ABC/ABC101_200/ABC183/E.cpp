#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

// 使う関数の前に記述しておく
// mll a = 1;という宣言で使用できる
// tabキーで下まで移動
template<ll MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr ll getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

using mll = Fp<MOD>;

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    REP(i, H) {
        cin >> s.at(i);
    }
    vector<vector<mll>> dp(H + 1, vector<mll>(W + 1, 0));
    dp.at(1).at(1) = 1;
    vector<vector<mll>> X = dp;
    vector<vector<mll>> Y = dp;
    vector<vector<mll>> Z = dp;
    FOR(i, 1, H) {
        FOR(j, 1, W) {
            if(s.at(i - 1).at(j - 1) == '#') {
                continue;
            }
            if(i == 1 && j == 1) {
                continue;
            }
            dp.at(i).at(j) = X.at(i).at(j - 1) + Y.at(i - 1).at(j) + Z.at(i - 1).at(j - 1);
            X.at(i).at(j) = X.at(i).at(j - 1) + dp.at(i).at(j);
            Y.at(i).at(j) = Y.at(i - 1).at(j) + dp.at(i).at(j);
            Z.at(i).at(j) = Z.at(i - 1).at(j - 1) + dp.at(i).at(j);
        }
    }

    cout << dp.at(H).at(W) << endl;
    return 0;
}