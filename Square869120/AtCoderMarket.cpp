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
    ll N;
    cin >> N;
    vector<ll> AB(N * 2);
    REP(i, N) {
        cin >> AB.at(i * 2) >> AB.at(i * 2 + 1);
    }

    ll ans = INF;

    FOR(i, 0, N * 2 - 1) {
        FOR(j, i, N * 2 - 1) {
            ll enterance = AB.at(i);
            ll exit = AB.at(j);
            ll sum = 0;
            REP(k, N) {
                ll A = AB.at(k * 2);
                ll B = AB.at(k * 2 + 1);
                sum += min(abs(A - enterance) + abs(B - A) + abs(exit - B), abs(B - enterance) + abs(A - B) + abs(exit - A));
            }
            ans = min(ans, sum);
        }
    }

    cout << ans << endl;
}