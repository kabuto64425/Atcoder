#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 998244353

signed main(){
    ll A, B, C;
    cin >> A >> B >> C;
    ll sumA = A;
    sumA *= (A + 1);
    sumA /= 2;
    sumA %= MOD;

    ll sumB = B;
    sumB *= (B + 1);
    sumB /= 2;
    sumB %= MOD;

    ll sumC = C;
    sumC *= (C + 1);
    sumC /= 2;
    sumC %= MOD;

    ll ans = (sumA * sumB) % MOD;
    ans = (ans * sumC) % MOD;

    cout << ans << endl;
}