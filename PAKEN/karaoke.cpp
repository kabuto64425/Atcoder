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
    vector<vector<ll>> A(N);
    REP(i, N) {
        vector<ll> vec(M);
        REP(j, M) {
            cin >> vec.at(j);
        }
        A.at(i) = vec;
    }

    ll ans = 0;

    for(ll i = 0; i <= M - 2; i++) {
        for(ll j = 0; j <= M - 1; j++) {
            ll score = 0;
            for(ll k= 0; k < N; k++) {
                score += max(A.at(k).at(i), A.at(k).at(j));
            }
            ans = max(ans, score);
        }
    }

    cout << ans << endl;
}