#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    ll A, B, C;
    cin >> N;
    cin >> A >> B >> C;
    ll ans = INF;
    for(ll a = 0; a <= 9999 and a * A <= N; a++) {
        for(ll b = 0; a + b <= 9999 and a * A + b * B <= N; b++) {
            ll rest = N - a * A - b * B;
            if(rest % C == 0) {
                ll c = rest / C;
                ans = min(ans, a + b + c);
            }
        }
    }

    cout << ans << endl;

    return 0;
}