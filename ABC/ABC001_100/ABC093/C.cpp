#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    ll oddCount = 0;
    if(A % 2 == 0) {
        oddCount++;
    }
    if(B % 2 == 0) {
        oddCount++;
    }
    if(C % 2 == 0) {
        oddCount++;
    }

    ll ans = 0;

    if(oddCount == 1) {
        if(A % 2 == 1) {
            A++;
        }
        if(B % 2 == 1) {
            B++;
        }
        if(C % 2 == 1) {
            C++;
        }
        ans++;
    }

    if(oddCount == 2) {
        if(A % 2 == 0) {
            A++;
        }
        if(B % 2 == 0) {
            B++;
        }
        if(C % 2 == 0) {
            C++;
        }
        ans++;
    }
    ll ma = max({A, B, C});
    ll mi = min({A, B, C});
    ll middle = A + B + C - ma - mi;
    ans += (ma - middle);
    ans += (middle - mi) / 2;
    cout << ans << endl;
    return 0;
}