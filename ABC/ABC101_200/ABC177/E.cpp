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
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    set<ll> s;
    bool isPairwise = true;
    for(ll i = 0; i < N; i++) {
        ll a = A.at(i);
        if(a == 1) {
            continue;
        }
        vector<pair<ll, ll>> pf = primeFactorization(a);
        for(pair<ll, ll> p : pf) {
            if(s.count(p.first)) {
                isPairwise = false;
            } else {
                s.insert(p.first);
            }
        }
        if(!isPairwise) {
            break;
        }
    }
    if(isPairwise) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    ll g = A.at(0);
    for(ll i = 1; i < N; i++) {
        g = gcd(g, A.at(i));
    }
    if(g == 1) {
        cout << "setwise coprime" << endl;
        return 0;
    }
    cout << "not coprime" << endl;
    return 0;
}