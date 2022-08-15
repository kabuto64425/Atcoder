#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> h(N);
    REP(i, N) {
        cin >> h.at(i);
    }
    sort(h.begin(), h.end());
    ll ans = INF;
    for(ll i = K - 1; i < N; i++) {
        ans = min(ans, h.at(i) - h.at(i - K + 1));
    }

    cout << ans << endl;
}