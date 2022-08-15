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
 * Nを素因数分解
 * 10^12までの値に対応
 */
void primeFactorization(ll N, vector<pair<ll, ll>> &res) {
    static bool isCalled = false;
    const ll M = 1000000;
    static vector<bool> isPrime(M + 1, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;

    static vector<ll> primes;

    if(!isCalled) {
        /* エラトステネスの篩 */
        for(ll i = 2; i <= M; i++) {
            if(!isPrime.at(i)) {
                continue;
            }

            primes.push_back(i);

            for(ll j = 2; i * j <= M; j++) {
                isPrime.at(i * j) = false;
            }
        }
        isCalled = true;
    }

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

    return;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> bucket(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        vector<pair<ll, ll>> res;
        primeFactorization(i, res);
        ll x = 1;
        for(pair<ll, ll> p : res) {
            if(p.second % 2 == 1) {
                x *= p.first;
            }
        }
        bucket.at(x)++;
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        ans += bucket.at(i) * bucket.at(i);
    }
    cout << ans << endl;
    return 0;
}