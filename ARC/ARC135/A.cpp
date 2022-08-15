#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

mint dfs(ll X, map<ll, mint> &m) {
    if(m.count(X)) {
        return m[X];
    }
    ll x = X / 2;
    ll y = (X + 1) / 2;
    if(x > ((ll)1e18) / y or x * y > X) {
        return m[X] = dfs(x, m) * dfs(y, m);
    } else {
        return m[X] = (mint) X;
    }
    //return m[X] = max(X, vec, dfs(X / 2, m) * dfs((X + 1) / 2, vec, m));
}

int main(){
    ll X;
    cin >> X;
    map<ll, mint> m;
    mint ans = dfs(X, m);
    cout << ans.val() << endl;
    return 0;
}