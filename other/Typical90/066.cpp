#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> L(N), R(N);
    for(ll i = 0; i < N; i++) {
        cin >> L.at(i) >> R.at(i);
    }
    long double ans = 0;
    for(ll i = 0; i < N - 1; i++) {
        for(ll j = i + 1; j < N; j++) {
            ll l1 = L.at(i);
            ll r1 = R.at(i);
            ll l2 = L.at(j);
            ll r2 = R.at(j);
            ll current = 0;
            for(ll k = l1; k <= r1; k++) {
                current += max(min(k - 1, r2) - l2 + 1, 0LL);
            }
            ans += current / (long double)((r1 - l1 + 1) * (r2 - l2 + 1));
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}