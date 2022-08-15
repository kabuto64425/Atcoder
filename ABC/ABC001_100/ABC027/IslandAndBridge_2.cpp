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

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for(ll &a : A) {
        cin >> a;
        sum += a;
    }
    if(sum % N != 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    ll ave = sum / N;
    ll x = 0;
    for(const ll &a : A) {
        x += (a - ave);
        if(x != 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}