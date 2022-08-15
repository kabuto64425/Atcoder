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
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    ll ans = 0;
    for(ll i = 0; i < N - 1; i++) {
        if(a.at(i) + a.at(i + 1) > x) {
            ll over = a.at(i) + a.at(i + 1) - x;
            if(a.at(i + 1) - over >= 0) {
                a.at(i + 1) -= over;
            } else {
                a.at(i) -= over - a.at(i + 1);
                a.at(i + 1) = 0;
            }
            ans += over;
        }
    }
    cout << ans << endl;
    return 0;
}