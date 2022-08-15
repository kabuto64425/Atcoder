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

/**
 * ※10^6までであればEratosthenesの構造体を使用したほうが計算量が小さくなります！（EratosthenesStructという名前でスニペット登録済み）
 */
// nを素因数分解する
void primeFactorize(ll n, vector<pair<ll, ll>> &res) {
    assert(n >= 0);
    res.clear();
    ll rem = n;
    for(ll i = 2; i * i <= n; i++) if(rem % i == 0) {
        ll exp = 0;
        while(rem % i == 0) {
            rem /= i;
            exp++;
        }
        res.emplace_back(i, exp);
    }
    if (rem != 1) {
        res.emplace_back(rem, 1);
    }
}

// nが素数かどうかを調べる
bool isPrime(ll n) {
    assert(n >= 0);
    vector<pair<ll, ll>> res;
    primeFactorize(n, res);
    return (res.size() == 1 and res.at(0).second == 1);
}

// nの約数の個数を求める
ll divisorsSize(ll n) {
    assert(n >= 0);
    vector<pair<ll, ll>> primes;
    primeFactorize(n, primes);
    ll res = 1;
    for(pair<ll, ll> p : primes) {
        res *= (p.second + 1);
    }
    return res;
}

// nの約数を列挙したものをresに格納(昇順)
// resは処理の最初にclearで中身を消している。
// 約数の個数を求めるときはこの関数ではなく、divisorsSizeを使用する
// (divisorsSizeは約数を列挙せずに求めるため、実行時間がより小さい)
void divisors(ll n, vector<ll> &res) {
    assert(n >= 0);
    res.clear();
    res.push_back(1);
    
    // n を素因数分解 (メンバ関数使用)
    vector<pair<ll, ll>> pf;
    primeFactorize(n, pf);
    
    // 約数列挙
    for (pair<ll, ll> p : pf) {
        ll s = (ll)res.size();
        for (ll i = 0; i < s; ++i) {
            ll v = 1;
            for (ll j = 0; j < p.second; ++j) {
                v *= p.first;
                res.push_back(res[i] * v);
            }
        }
    }
    sort(res.begin(), res.end());
}

int main(){
    string S;
    cin >> S;
    ll N = S.length();
    set<char> cs;
    for(char c : S) {
        cs.insert(c);
    }
    vector<char> cv;
    for(char c : cs) {
        cv.push_back(c);
    }
    vector<char> nv = {'1', '3', '5', '7', '9'};
    ll M = cv.size();
    if(M >= 6) {
        cout << - 1 << endl;
        return 0;
    }
    do {
        string t = "";
        map<char, char> m;
        for(ll i = 0; i < M; i++) {
            m[cv.at(i)] = nv.at(i);
        }
        for(ll i = 0; i < N; i++) {
            t += m[S.at(i)];
        }
        ll x = stoll(t);
        if(isPrime(x)) {
            cout << x << endl;
            return 0;
        }
    } while (next_permutation(nv.begin(), nv.end()));
    cout << - 1 << endl;
    return 0;
}