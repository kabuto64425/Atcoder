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
    vector<ll> h(N);
    for(ll &elm : h) {
        cin >> elm;
    }
    ll ans = 0;
    for(ll i = 1; i <= 100; i++) {
        bool flag = false;
        for(ll j = 0; j < N; j++) {
            if(i <= h[j] && !flag) {
                ans++;
                flag = true;
            } else if(i > h[j]) {
                flag = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}