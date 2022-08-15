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
    for(auto &a: A) {
        cin >> a;
    }
    vector<ll> sum(N + 1, 0);
    for(ll i = 0; i < N; i++) {
        sum.at(i + 1) = sum.at(i) + A.at(i);
    }

    for(ll k = 1; k <= N; k++) {
        ll ans = 0;
        for(ll i = 0; i < N - k + 1; i++) {
            ans = max(ans, sum.at(k + i) - sum.at(i));
        }
        cout << ans << endl;
    }
    return 0;
}