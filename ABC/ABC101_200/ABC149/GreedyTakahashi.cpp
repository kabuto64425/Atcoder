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
    ll A, B, K;
    cin >> A >> B >> K;
    ll ansA = max(0LL, A - K);
    ll ansB;
    if(A - K < 0) {
        ansB = max(0LL, B - (K - A));
    } else {
        ansB = B;
    }
    cout << ansA << " " << ansB << endl;
    return 0;
}