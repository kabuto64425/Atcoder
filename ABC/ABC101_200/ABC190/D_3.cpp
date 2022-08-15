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
    ll ans = 0;
    vector<ll> vec;
    for(ll i = 1; i * i <= 2 * N; i++) {
        if(2 * N % i == 0) {
            vec.push_back(i);
            vec.push_back(2 * N / i);
        }
    }
    for(const ll &x : vec) {
        ll y = 2 * N / x;
        if((x % 2 == 1 and y % 2 == 0) or (x % 2 == 0 and y % 2 == 1)) {
            ans++;
        }
    }
    cout << ans << endl;
}