#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

void cf(long double x, long double r, ll &low, ll &high){

    low = ceil(x-r);
    high = floor(x+r);
}

int main(){
    long double X, Y, R;
    cin >> X >> Y >> R;
    R+=1e-14;
    ll start, end, top, bottom;

    cf(X, R, start, end);

    long double p;

    ll ans = 0;
    for(ll i = start; i<=end; i++){
        p = sqrtl(pow(R, 2)-pow((X-(double)i),2));

        cf(Y, p, bottom, top);

        ans += top - bottom + 1;
    }
    cout << ans << endl;
    return 0;
}