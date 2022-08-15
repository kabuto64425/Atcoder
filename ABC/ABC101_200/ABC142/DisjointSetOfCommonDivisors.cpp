#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll A, B;
    cin >> A >> B;

    ll limit = sqrt(max(A, B));
    vector<bool> isPrime(limit + 1, true);
    isPrime.at(0) = false;
    isPrime.at(1) = false;
    vector<pair<ll, ll>> vecA;
    vector<pair<ll, ll>> vecB;
    ll ans = 1;
    for(ll i = 2; i <= limit; i++) {
        /* エラトステネスの篩 */
        if(!isPrime.at(i)) {
            continue;
        }

        for(ll j = 2; i * j <= limit; j++) {
            isPrime.at(i * j) = false;
        }

        ll countA = 0;
        while(A % i == 0) {
            A /= i;
            countA++;
        }

        ll countB = 0;
        while(B % i == 0) {
            B /= i;
            countB++;
        }

        if(countA > 0 && countB > 0) {
            ans++;
        }
    }

    if(A != 1 && A == B) {
        ans++;
    }

    cout << ans << endl;
}