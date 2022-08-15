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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A.at(i);
    }
    vector<ll> B(N);
    REP(i, N) {
        cin >> B.at(i);
    }
    vector<ll> C(N);
    REP(i, N) {
        cin >> C.at(i);
    }

    ll ans = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    REP(i, N) {
        ll middle = B.at(i);
        ll upper = lower_bound(A.begin(), A.end(), middle) - A.begin();
        ll lower = C.end() - upper_bound(C.begin(), C.end(), middle);
        ans += upper * lower;
    }

    cout << ans << endl;
}