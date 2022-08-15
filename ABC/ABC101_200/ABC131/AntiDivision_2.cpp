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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll X = (A - 1) - (A - 1) / C - (A - 1) / D + (A - 1) / lcm(C, D);
    ll Y = B - B / C - B / D + B / lcm(C, D);
    cout << Y - X << endl;
    return 0;
}