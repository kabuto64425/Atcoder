#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, K;
    cin >> N >> K;
    ll R, S, P;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    ll ans = 0;
    vector<bool> zeroFlag(N, false);
    REP(i, N) {
        if(i - K >= 0) {
            if(T.at(i) == T.at(i - K) && !zeroFlag.at(i - K)) {
                zeroFlag.at(i) = true;
                continue;
            }
        }
        if(T.at(i) == 'r') {
            ans += P;
        } else if(T.at(i) == 's') {
            ans += R;
        } else if(T.at(i) == 'p') {
            ans += S;
        }
    }
    cout << ans << endl;
}