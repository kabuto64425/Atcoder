#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll K;
    cin >> K;
    ll X = 7;
    for(ll i = 1; i <= K; i++) {
        if(X % K == 0) {
            cout << i << endl;
            return 0;
        }
        X = X % K;
        X = X * 10 + 7;
    }
    cout << -1 << endl;
    return 0;
}