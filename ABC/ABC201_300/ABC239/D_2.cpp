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
 * この構造体を呼び出すのは1回だけにする（呼び出し時に10^6までの素数を列挙するため）
 * （ループ処理内などで繰り返し呼び出すと処理時間が大きくなるので注意。）
 */
struct PrimeStruct {
    // 10^6までの素数が格納される
    vector<ll> primes;
    PrimeStruct() {
        primeFlags.assign(M + 1, true);
        primeFlags.at(0) = false;
        primeFlags.at(1) = false;

        /* エラトステネスの篩 */
        for(ll i = 2; i <= M ; i++) {
            if(!primeFlags.at(i)) {
                continue;
            }

            primes.push_back(i);

            for(ll j = 2; i * j <= M; j++) {
                primeFlags.at(i * j) = false;
            }
        }
    }

    // Nが素数化を判定
    // 10^12まで対応
    bool isPrime(ll N) {
        assert(N >= 0 and N <= M * M);
        if(N <= M) {
            return primeFlags.at(N);
        }
        for(ll prime : primes) {
            if(prime * prime > N) {
                return true;
            }
            if(N % prime == 0) {
                return false;
            }
        }
        return true;
    }

    // Nを素因数分解してその結果をresに格納
    // 10^12まで対応
    // resは処理の最初にclearで中身を消している。
    void primeFactorization(ll N, vector<pair<ll, ll>> &res) {
        assert(N >= 0 and N <= M * M);
        res.clear();

        for(ll prime : primes) {
            if(prime * prime > N) {
                break;
            }

            ll count = 0;
            while(N % prime == 0) {
                N /= prime;
                count++;
            }

            if(count > 0) {
                res.push_back({prime, count});
            }
        }

        if(N != 1) {
            res.push_back({N, 1});
        }
    }

    // Nの約数の個数を求める
    // 10^12まで対応
    ll divisorsSize(ll N) {
        assert(N >= 0 and N <= M * M);
        vector<pair<ll, ll>> primes;
        primeFactorization(N, primes);
        ll res = 1;
        for(pair<ll, ll> p : primes) {
            res *= (p.second + 1);
        }
        return res;
    }

    // Nの約数を列挙したものをresに格納(昇順)
    // 10^12まで対応
    // resは処理の最初にclearで中身を消している。
    // 約数の個数を求めるときはこの関数ではなく、divisorsSizeを使用する
    // (divisorsSizeは約数を列挙せずに求めるため、実行時間がより小さい)
    void divisors(ll N, vector<ll> &res) {
        assert(N >= 0 and N <= M * M);
        res.clear();
        vector<pair<ll, ll>> primes;
        primeFactorization(N, primes);
        recurDivisors(res, primes, 1, 0);
        sort(res.begin(), res.end());
    }

    private:
        const ll M = 1000000;
        vector<ll> primeFlags;
        
        void recurDivisors(vector<ll> &res, const vector<pair<ll, ll>> &vec, ll current, ll x) {
            if(x == (ll)vec.size()) {
                res.push_back(current);
                return;
            }
            for(ll i = 0; i <= vec.at(x).second; i++) {
                recurDivisors(res, vec, current, x + 1);
                current *= vec.at(x).first;
            }
        }
};

int main(){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    PrimeStruct ps;
    for(ll i = A; i <= B; i++) {
        bool flag = true;
        for(ll j = C; j <= D; j++) {
            if(ps.isPrime(i + j)) {
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