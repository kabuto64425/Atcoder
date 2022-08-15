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

int main(){
    vector<ll> ABCDE(5);
    for(ll &elm : ABCDE) {
        cin >> elm;
    }

    ll ans = INF;

    do {
        ll current = 0;
        for(ll i = 0; i < 5; i++) {
            ll time = ABCDE.at(i) + (10 - current % 10) % 10;
            current += time;
        }
        ans = min(ans, current);
    } while (next_permutation(ABCDE.begin(), ABCDE.end()));

    cout << ans << endl;

    return 0;
}