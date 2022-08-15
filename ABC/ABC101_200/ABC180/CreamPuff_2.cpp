#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
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

void recur(vector<ll> &ans, const vector<pair<ll, ll>> &vec, ll current, ll x) {
    if(x == 0) {
        ans.push_back(current);
        return;
    }
    for(ll i = 0; i < vec.at(x - 1).second + 1; i++) {
        recur(ans, vec, current, x - 1);
        current *= vec.at(x - 1).first;
    }
}

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> vec = primeFactorization(N);
    vector<ll> ans;
    recur(ans, vec, 1, vec.size());
    sort(ans.begin(), ans.end());
    for(const ll &elm : ans) {
        cout << elm << endl;
    }
    return 0;
}