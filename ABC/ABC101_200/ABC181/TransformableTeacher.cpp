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

    vector<ll> CumulativeSum1(N + 1, 0);
    vector<ll> CumulativeSum2(N + 2, 0);
    for(ll i = 1; i <= N; i += 2) {
        CumulativeSum1.at(i) += CumulativeSum1.at(max((ll)0, i - 2)) + H.at(i - 1);
        if(i < N) {
            CumulativeSum2.at(i + 1) += CumulativeSum2.at(max((ll)0, i - 1)) + H.at(i);
        } else {
            CumulativeSum2.at(i + 1) = CumulativeSum2.at(max((ll)0, i - 1));
        }
    }

    ll ans = INF;
    REP(i, M) {
        ll index = lower_bound(H.begin(), H.end(), W.at(i)) - H.begin();
        if(index % 2 == 0) {
            ll current = CumulativeSum1.at(N) - CumulativeSum1.at(max((ll) 0, index - 1)) * 2 - CumulativeSum2.at(N - 1) + CumulativeSum2.at(index) * 2 - W.at(i);
            ans = min(ans, current);
        } else {
            ll current = CumulativeSum1.at(N) - CumulativeSum1.at(index) * 2 - CumulativeSum2.at(N - 1) + CumulativeSum2.at(index - 1) * 2 + W.at(i);
            ans = min(ans, current);
        }
    }
    cout << ans << endl;
}