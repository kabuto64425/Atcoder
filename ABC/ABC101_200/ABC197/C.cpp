#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000LL; //10^15:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll ans = INF;
    for(ll bit = 0; bit < (1 << (N - 1)); bit++) {
        ll current = 0;
        ll now = A.at(0);
        for(ll i = 0; i < N - 1; i++) {
            if(bit & (1 << i)) {
                current = current ^ now;
                now = A.at(i + 1);
            } else {
                now = now | A.at(i + 1);
            }
        }
        current = current ^ now;
        ans = min(ans, current);
    }
    cout << ans << endl;
    return 0;
}