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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll m = A.at(0);
    ll g = A.at(0);
    for(ll i = 1; i < N; i++) {
        m = max(m, A.at(i));
        g = gcd(g, A.at(i));
    }
    if(m - K < 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } else if((m - K) % g != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << "POSSIBLE" << endl;
    return 0;
}