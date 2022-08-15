#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

vector<bool> isPrimeVec() {
    vector<bool> isPrime(1100000, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;

    for(ll i = 2; i <= 100000; i++) {
        /* エラトステネスの篩 */
        if(!isPrime.at(i)) {
            continue;
        }

        for(ll j = 2; i * j <= 100000; j++) {
            isPrime.at(i * j) = false;
        }
        /* ここまで */
    }

    return isPrime;
}

int main(){
    vector<bool> isP = isPrimeVec();
    vector<ll> sum(100001, 0);
    for(ll i = 3; i <= 100000; i += 2) {
        sum.at(i) += sum.at(i - 2);
        if(isP.at(i) and isP.at((i + 1) / 2)) {
            sum.at(i)++;
        }
    }
    ll Q;
    cin >> Q;
    vector<pair<ll, ll>> lr(Q);
    for(auto &elm : lr) {
        cin >> elm.first >> elm.second;
    }
    for(const auto &elm : lr) {
        cout << sum.at(elm.second) - sum.at(max(1LL, elm.first - 2)) << endl;
    }
    return 0;
}