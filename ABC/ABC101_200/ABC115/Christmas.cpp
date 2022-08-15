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

vector<vector<bool>> memo(100);

ll countLayers(ll n) {
    ll res = 4;
    REP(i, n) {
        res *= 2;
    }
    return res - 3;
}

ll countPatties(ll n) {
    ll res = 2;
    REP(i, n) {
        res *= 2;
    }
    return res - 1;
}

ll burger(ll N, ll X) {
    if(X == 0) {
        return 0;
    }
    if(N == 0) {
        return 1;
    }
    ll layers = countLayers(N - 1);
    if(X <= layers + 1) {
        return burger(N - 1, X - 1);
    }
    return countPatties(N - 1) + 1 + burger(N - 1, X - layers - 2);
}

int main(){
    ll N, X;
    cin >> N >> X;
    cout << burger(N, X) << endl;
    return 0;
}