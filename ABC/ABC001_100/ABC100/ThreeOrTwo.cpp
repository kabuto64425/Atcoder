#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法



int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(auto &x: a) {
        cin >> x;
    }

    ll ans = 0;

    for(auto x : a) {
        while(x % 2 == 0) {
            x /= 2;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}