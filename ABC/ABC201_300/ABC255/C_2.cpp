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
    if(D < 0) {
        A = A + D * (N - 1);
        D = -D;
    }
    ll ok = 1;
    ll ng = N + 1;
    while(abs(ok - ng) != 1) {
        ll mid = (ok + ng) / 2;
        if(X >= A + D * (mid - 1)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    if(ok == N) {
        cout << abs(A + D * (N - 1) - X) << endl;
    } else {
        cout << min(abs(A + D * (ok - 1) - X), abs(A + D * ok - X)) << endl;
    }
    return 0;
}