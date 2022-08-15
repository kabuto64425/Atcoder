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
    ll ans = 0;
    ll current = 0;
    FOR(i, 2, 1000) {
        ll count = 0;
        FOR(j, 0, N - 1) {
            if(A.at(j) % i == 0) {
                count++;
            }
        }
        if(count > current) {
            ans = i;
            current = count;
        }
    }
    cout << ans << endl;
}