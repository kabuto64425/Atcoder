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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }

    vector<ll> isAns(1100000, true);

    for(const ll &a : A) {
        vector<pair<ll, ll>> res = primeFactorization(a);
        for(const pair<ll, ll> &elm : res) {
            ll x = elm.first;
            if(!isAns.at(x)) {
                continue;
            }

            for(ll j = 1; x * j <= 100000; j++) {
                isAns.at(x * j) = false;
            }
        }
    }

    ll count = 0;
    vector<ll> ans;

    for(ll i = 1; i <= M; i++) {
        if(isAns.at(i)) {
            count++;
            ans.push_back(i);
        }
    }

    cout << count << endl;

    for(const ll &elm : ans) {
        cout << elm << endl;
    }

    return 0;
}