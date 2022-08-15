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

ll countLayers(ll level) {
    ll res = 4;
    for(ll i = 0; i < level; i++) {
        res *= 2;
    }
    res -= 3;
    return res;
}

ll countPaiites(ll level) {
    ll res = 2;
    for(ll i = 0; i < level; i++) {
        res *= 2;
    }
    res -= 1;
    return res;
}

ll func(ll level, ll eat) {
    if(eat == 0) {
        return 0;
    }
    if(level == 0) {
        return 1;
    }
    ll pLayers = countLayers(level - 1);
    if(eat <= pLayers + 1) {
        return func(level - 1, eat - 1);
    }
    return countPaiites(level - 1) + 1 + func(level - 1, eat - pLayers - 2);
}

int main(){
    ll N, X;
    cin >> N >> X;
    cout << func(N, X) << endl;
    return 0;
}