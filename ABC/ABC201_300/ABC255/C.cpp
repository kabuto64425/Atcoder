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
    ll X, A, D, N;
    cin >> X >> A >> D >> N;
    ll firstA = A;
    ll lastA = A + D * (N - 1);
    if(X <= min(firstA, lastA)) {
        cout << abs(min(firstA, lastA) - X) << endl;
        return 0;
    }
    if(max(firstA, lastA) <= X) {
        cout << abs(X - max(firstA, lastA)) << endl;
        return 0;
    }
    ll n = (X - A) / D + 1;
    ll ans = INF;
    for(ll i = -10; i <= 10; i++) {
        chmin(ans, abs(X - (A + D * (n + i - 1))));
    }
    cout << ans << endl;
    return 0;
}