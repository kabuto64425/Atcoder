#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = LLONG_MAX;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> h(N);
    for(ll &elm : h) {
        cin >> elm;
    }
    vector<ll> dp(N + 1, INF);
    dp.at(0) = 0;
    dp.at(1) = 0;
    for(ll i = 2; i <= N; i++) {
        dp.at(i) = min(dp.at(i), dp.at(i - 1) + abs(h.at(i - 1) - h.at(i - 2)));
        if(i >= 3) {
            dp.at(i) = min(dp.at(i), dp.at(i - 2) + abs(h.at(i - 1) - h.at(i - 3)));
        }
    }
    cout << dp.at(N) << endl;
    return 0;
}