#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    mint ans = 0;
    ll d = 1;
    for(ll i = 0; i < 18; i++) {
        if(d * 10 > N) {
            mint x = (1 + N - d + 1);
            x *= (N - d + 1);
            x /= 2;
            ans += x;
            //ans += (1 + N - d + 1) * (N - d + 1) / 2;
            break;
        }
        mint x = (1 + d * 9);
        x *= (d * 9);
        x /= 2;
        ans += x;
        d *= 10;
    }
    cout << ans.val() << endl;
    return 0;
}