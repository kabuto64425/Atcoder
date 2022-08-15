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
    ll A, B, C, X;
    cin >> A >> B >> C >> X;
    long double ans;
    if(X <= A) {
        ans = 1;
    }
    else if(X >= A + 1 and X <= B) {
        ans = C / (long double)(B - A);
    }
    else {
        ans = 0;
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}