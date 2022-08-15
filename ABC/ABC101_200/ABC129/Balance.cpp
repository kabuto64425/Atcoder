#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> W(N);
    for(ll &w : W) {
        cin >> w;
    }
    ll ans = accumulate(W.begin(), W.end(), 0LL);
    ll S1 = accumulate(W.begin(), W.end(), 0LL);
    ll S2 = 0;
    for(ll i = 0; i < N; i++) {
        S1 -= W.at(i);
        S2 += W.at(i);
        ans = min(ans, abs(S1 - S2));
    }
    cout << ans << endl;
    return 0;
}