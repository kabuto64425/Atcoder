#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

vector<pair<ll, ll>> primeFactorization(ll n, vector<bool> &isPrime) {
    ll limit = sqrt(n);
    vector<pair<ll, ll>> vec;
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
        while(n % i == 0) {
            n /= i;
            count++;
        }

        if(count > 0) {
            vec.push_back({i, count});
        }
    }

    if(n != 1) {
        vec.push_back({n, 1});
    }
    return vec;
}

signed main(){
    //入力
    ll N;
    cin >> N;

    vector<bool> isPrime(110000, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;

    ll ans = 0;

    for(ll i = 1; i <= N; i += 2) {
        vector<pair<ll, ll>> vec = primeFactorization(i, isPrime);
        ll res = 1;
        for(pair<ll, ll> v : vec) {
            res *= (v.second + 1);
        }
        if(res == 8) {
            ans++;
        }
    }
    cout << ans << endl;
}