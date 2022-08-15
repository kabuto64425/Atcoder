#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll A, B;
    cin >> A >> B;
    ll minA, maxA;
    ll minB, maxB;

    minA = (A * 100 + 7) / 8;
    maxA = ((A + 1) * 100 + 7) / 8 - 1;
    minB = (B * 100 + 9) / 10;
    maxB = ((B + 1) * 100 + 9) / 10 - 1;

    ll ans = -1;
    if(minA <= maxB && maxA >= minB) {
        ans = max(minA, minB);
    }
    cout << ans <<endl;
}