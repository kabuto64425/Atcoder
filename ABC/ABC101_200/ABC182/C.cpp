#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

ll digsum(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

signed main(){
    ll N;
    cin >> N;
    vector<ll> dig;
    while(N > 0) {
        dig.push_back(N % 10);
        N /= 10;
    }
    ll ans = INF;
    ll size = dig.size();
    bool flag = false;
    for(ll bit = 1; bit < (1 << size); bit++) {
        ll current = 0;
        ll x = size;
        for(ll i = 0; i < size; i++) {
            if(bit & (1 << i)) {
                current += dig.at(i);
                x--;
            }
        }
        if(current % 3 == 0) {
            flag = true;
            ans = min(ans, x);
        }
    }
    if(flag) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}