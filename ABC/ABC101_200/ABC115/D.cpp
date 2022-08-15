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

// xのn乗を計算
ll mod_pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*x;
        x = x*x;
        n >>= 1;
    }
    return res;
}

ll layer(ll L) {
    return pow(2, L + 2) - 3;
}

ll patty(ll L) {
    return pow(2, L + 1) - 1;
}

ll recur(ll L, ll rest) {
    if(L == 0) {
        if(rest >= 1) {
            return 1;
        } else {
            return 0;
        }
    }
    ll underLayer = layer(L - 1) + 2;
    if(rest >= underLayer) {
        return patty(L - 1) + 1 + recur(L - 1, rest - underLayer);
    } else {
        return recur(L - 1, rest - 1);
    }
}

int main(){
    ll N, X;
    cin >> N >> X;
    cout << recur(N, X) << endl;
    return 0;
}