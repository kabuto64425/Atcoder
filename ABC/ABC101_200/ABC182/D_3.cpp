#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

int main(){
    ll N ;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll ans = 0;
    ll right = 0;
    ll x = 0;
    vector<ll> sum(N + 1, 0);
    FOR(i, 1, N) {
        sum.at(i) = sum.at(i - 1) + A.at(i - 1);
        right = max(right, sum.at(i));
        ans = max(ans, x + right);
        x += sum.at(i);
    }
    cout << ans << endl;
    return 0;
}