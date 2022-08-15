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

    if(K % 2 == 0) {
        ll x = (N / K);
        ll y = (N / K);
        if (N % K >= K / 2) {
            y++;
        }
        cout << x * x * x + y * y * y << endl;
    } else {
        cout << (N / K) * (N / K) * (N / K) << endl;
    }
}