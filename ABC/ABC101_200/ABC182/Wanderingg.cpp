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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> sum(N, 0);
    ll ans = 0;
    ll right = -INF;
    ll x = 0;
    REP(i, N) {
        if(i > 0) {
            sum[i] = sum[i - 1] + A[i];
        } else {
            sum[i] = A[i];
        }
        right = max(right, sum[i]);
        ans = max(ans, x + right);
        x += sum[i];
    }
    cout << ans << endl;
    return 0;
}