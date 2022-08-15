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
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    vector<ll> W(M);
    REP(i, N) {
        cin >> H.at(i);
    }
    REP(i, M) {
        cin >> W.at(i);
    }
    sort(H.begin(), H.end());
    ll sum1 = 0;
    ll sum2 = 0;
    REP(i, N - 1) {
        if(i % 2 == 0) {
            sum1 += (H.at(i + 1) - H.at(i));
        } else {
            sum2 += (H.at(i + 1) - H.at(i));
        }
    }

    ll sum = sum1 + sum2;


    ll ans = INF;

    REP(i, M) {
        ll ng = upper_bound(H.begin(), H.end(), W.at(i)) - H.begin();
        ll ok = ng - 1;
        if(ng >= N) {
            abs(H.at(ok) - W.at(i));
            ans = min(ans, sum1 + abs(H.at(ok) - W.at(i)));
        } else {
            ll okAbs = abs(H.at(ok) - W.at(i));
            ll ngAbs = abs(H.at(ng) - W.at(i));
            if(okAbs >= ngAbs) {
                
            }
        }
    }

    cout << ans << endl;
}