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

ll countDigits(ll n) {
    ll res = 0;
    while(n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 1; i <= 999999; i++) {
        ll digits = countDigits(i);
        ll num = i;
        for(ll j = 0; j < digits; j++) {
            num *= 10;
        }
        num += i;
        if(num <= N) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}