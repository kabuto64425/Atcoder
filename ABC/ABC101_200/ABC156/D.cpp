#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

mint fact(ll n) {
    if(n <= 0) {
        return 1;
    }
    mint res = 1;
    for(ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

mint combination(ll n, ll r) {
    mint res = 1;
    for(ll i = 1; i <= r; i++) {
        res *= (n - r + i);
        res /= i;
    }
    return res.val();
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    mint ans = ((mint) 2).pow(n);
    ans--;
    cout << (ans - combination(n, a) - combination(n, b)).val() << endl;
    return 0;
}