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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> ans(N, 0);
    for(ll i = 1; i <= N - 1; i++) {
        for(ll j = i; j <= N; j++) {
            ll distance = min({abs(j - i), abs(X - i) + abs(Y - j) + 1, abs(Y - i) + abs(X - j) + 1});
            ans.at(distance)++;
        }
    }
    FOR(i, 1, N - 1) {
        cout << ans.at(i) << endl;
    }
}