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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll A, B, H, M;
    cin >> A >> B >> H >> M;
    long double radm = M_PI * M / 30;
    long double radh = M_PI * (60 * H + M) / 360;
    long double radd = abs(radm - radh);
    radd = min(radd, 2 * M_PI - radd);
    long double ans = A * A + B * B - 2 * A * B * cosl(radd);
    ans = sqrtl(ans);
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}