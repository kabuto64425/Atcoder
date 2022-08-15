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
 * エラトステネスの篩を使って10^6以下の整数の素数判定・素因数分解・約数列挙ができる構造体
 * この構造体を呼び出すのは1回だけにする（呼び出し時に10^6までの素数を列挙するため、ループ処理内などで繰り返し呼び出すと処理時間が大きくなる）
 * 10^12などの大きい数字の約数や素因数分解をする場合は、PrimeAndDivisorsでスニペット登録している関数群を使用する
 */
struct Eratosthenes {
    // 10^6までの素数が格納される
    vector<ll> primes;
    Eratosthenes() {
        primeFlags.assign(M + 1, true);
        primeFlags.at(0) = false;
        primeFlags.at(1) = false;
        minfactor.assign(M + 1, -1);
        minfactor.at(1) = 1;

        /* エラトステネスの篩 */
        for(ll i = 2; i <= M ; i++) {
            if(!primeFlags.at(i)) {
                continue;
            }

            primes.push_back(i);
            // i についての情報更新
            minfactor[i] = i;

            for(ll j = i * 2; j <= M; j += i) {
                primeFlags.at(j) = false;
                // j は i で割り切れる旨を更新
                if (minfactor[j] == -1) {
                    minfactor[j] = i;
                }
            }
        }
    }

    // nが素数かを判定
    bool isPrime(ll n) {
        assert(n >= 0 and n <= M);
        return primeFlags.at(n);
    }

    // nを素因数分解してその結果をresに格納
    // resは処理の最初にclearで中身を消している。
    void primeFactorize(ll n, vector<pair<ll, ll>> &res) {
        assert(n >= 0 and n <= M);
        res.clear();
        
        while (n > 1) {
            ll p = minfactor.at(n);
            ll exp = 0;
            
            // n で割り切れる限り割る
            while (minfactor.at(n) == p) {
                n /= p;
                exp++;
            }
            res.emplace_back(p, exp);
        }
    }

    // nの約数の個数を求める
    ll divisorsSize(ll n) {
        assert(n >= 0 and n <= M);
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
        assert(n >= 0 and n <= M);
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

    private:
        const ll M = 1000000;
        vector<ll> primeFlags;
        // 整数 i を割り切る最小の素数
        vector<ll> minfactor;
};

int main(){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    Eratosthenes es;
    for(ll i = A; i <= B; i++) {
        bool flag = true;
        for(ll j = C; j <= D; j++) {
            if(es.isPrime(i + j)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
    return 0;
}