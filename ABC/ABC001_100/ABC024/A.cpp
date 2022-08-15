#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll A, B, C, K;
    ll S, T;
    cin >> A >> B >> C >> K;
    cin >> S >> T;
    ll ans = 0;
    ans += A * S + B * T;
    if(S + T >= K) {
        ans -= (S + T) * C;
    }
    cout << ans << endl;
    return 0;
}