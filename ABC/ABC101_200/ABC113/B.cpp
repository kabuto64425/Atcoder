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
    ll N;
    cin >> N;
    ll T, A;
    cin >> T >> A;
    vector<ll> H(N);
    for(ll &h : H) {
        cin >> h;
    }
    ll ans = INF;
    ll m = INF;
    for(ll i = 1; i <= N; i++) {
        ll x = abs(1000 * T - 6 * H.at(i - 1) - 1000 * A);
        if(m > x) {
            m = x;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}