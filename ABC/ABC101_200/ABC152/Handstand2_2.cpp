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
    vector<vector<ll>> vec(10, vector<ll>(10, 0));
    for(ll i = 1; i <= N; i++) {
        ll x = i;
        while(x / 10 > 0) {
            x /= 10;
        }
        ll y = i % 10;
        vec.at(x).at(y)++;
    }
    ll ans = 0;
    for(ll p = 1; p <= 9; p++) {
        for(ll q = 1; q <= 9; q++) {
            ans += vec.at(p).at(q) * vec.at(q).at(p);
        }
    }
    cout << ans << endl;
    return 0;
}