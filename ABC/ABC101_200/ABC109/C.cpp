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
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N);
    for(ll &elm : x) {
        cin >> elm;
    }
    vector<ll> diffs(N);
    for(ll i = 0; i < N; i++) {
        diffs.at(i) = abs(x.at(i) - X);
    }
    ll ans = diffs.at(0);
    for(ll i = 1; i < N; i++) {
        ans = gcd(ans, diffs.at(i));
    }
    cout << ans << endl;
    return 0;
}