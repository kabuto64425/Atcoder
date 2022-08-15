#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A.at(i);
    }

    ll ans = 1;

    sort(A.begin(), A.end());

    REP(i, N) {
        if(A.at(i) != 0 && ans > 1000000000000000000 / A.at(i)) {
            ans = -1;
            break;
        }
        ans = ans * A.at(i);
    }

    cout << ans << endl;
}