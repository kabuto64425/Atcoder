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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

vector<bool> isPrime(1100000, true);

vector<pair<ll, ll>> primeFactorization(ll N) {
    
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
    primeFactorization((ll)1e12);
    vector<ll> ps;
    for(ll i = 1; i <= 1000000; i++) {
        if(isPrime.at(i)) {
            ps.push_back(i);
        }
    }
    ll M = ps.size();
    ll ans = 0;
    for(ll i = 0; i < M; i++) {
        for(ll j = i + 1; j < M; j++) {
            ll p = ps.at(i);
            ll q = ps.at(j);
            if(q * q * q > ((ll)1e18) / p) {
                break;
            }
            if(p * q * q * q > N) {
                break;
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}