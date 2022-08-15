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
    vector<ll> t(N);
    for(ll &elm : t) {
        cin >> elm;
    }
    ll ans = INF;
    for(ll bit = 0; bit < (1 << N); bit++) {
        ll first = 0;
        ll second = 0;
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                first += t[i];
            } else {
                second += t[i];
            }
        }
        ans = min(ans, max(first, second));
    }
    cout << ans << endl;
    return 0;
}