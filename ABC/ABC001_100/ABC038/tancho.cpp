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
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    ll ans = 0;
    ll current = 1;
    for(ll i = 1; i < N; i++) {
        if(a[i] <= a[i - 1]) {
            ans += current * (current + 1) / 2;
            current = 1;
        } else {
            current++;
        }
    }
    ans += current * (current + 1) / 2;
    cout << ans << endl;
    return 0;
}