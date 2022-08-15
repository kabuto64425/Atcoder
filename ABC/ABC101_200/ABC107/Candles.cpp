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
    vector<ll> x(N);
    for(ll &elm : x) {
        cin >> elm;
    }

    ll ans = INF;

    for(ll i = 0; i < N - K + 1; i++) {
        if(x.at(i) < 0 and x.at(i + K - 1) < 0) {
            ans = min(ans, abs(x.at(i)));
        } else if(x.at(i) < 0 and x.at(i + K - 1) >= 0) {
            ans = min({ans, abs(x.at(i)) * 2 + abs(x.at(i + K - 1)), abs(x.at(i)) + abs(x.at(i + K - 1)) * 2});
        } else {
            ans = min(ans, abs(x.at(i + K - 1)));
        }
    }

    cout << ans << endl;

    return 0;
}