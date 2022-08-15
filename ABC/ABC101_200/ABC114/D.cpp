#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

vector<pair<ll, ll>> primeFactorization(ll N) {
    static vector<bool> isPrime(1100000, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;

    vector<pair<ll, ll>> res;
    ll limit = sqrt(N);
    for(ll i = 2; i <= limit; i++) {
        /* エラトステネスの篩 */
        if(!isPrime.at(i)) {
            continue;
        }

        for(ll j = 2; i * j <= limit; j++) {
            isPrime.at(i * j) = false;
        }
        /* ここまで */

        ll count = 0;
        while(N % i == 0) {
            N /= i;
            count++;
        }

        if(count > 0) {
            res.push_back({i, count});
        }
    }

    if(N != 1) {
        res.push_back({N, 1});
    }

    return res;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(101, 0);
    for(ll i = 1; i <= N; i++) {
        vector<pair<ll, ll>> primes = primeFactorization(i);
        for(const pair<ll, ll> &prime : primes) {
            vec.at(prime.first) += prime.second;
        }
    }
    ll ans = 0;
    ll four = 0;
    ll two = 0;
    for(ll i = 1; i <= N; i++) {
        if(vec.at(i) >= 4) {
            four++;
        } else if(vec.at(i) >= 2) {
            two++;
        }
    }
    if(four >= 2) {
        ans += (four * (four - 1) / 2) * two;
    }
    if(four >= 3) {
        ans += (four * (four - 1) * (four - 2) / 6);
    }

    ll twentyfour = 0;
    two = 0;
    for(ll i = 1; i <= N; i++) {
        if(vec.at(i) >= 24) {
            twentyfour++;
        } else if(vec.at(i) >= 2) {
            two++;
        }
    }
    ans += twentyfour * two;
    if(twentyfour >= 2) {
        ans += (twentyfour * (twentyfour - 1) / 2);
    }

    ll fourteen = 0;
    four = 0;
    for(ll i = 1; i <= N; i++) {
        if(vec.at(i) >= 14) {
            fourteen++;
        } else if(vec.at(i) >= 4) {
            four++;
        }
    }
    ans += fourteen * four;
    if(fourteen >= 2) {
        ans += (fourteen * (fourteen - 1) / 2);
    }

    for(ll i = 1; i <= N; i++) {


        if(vec.at(i) >= 74) {
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}