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

bool isArithmetic(ll N) {
    if(N <= 99) {
        return true;
    }
    string S = to_string(N);
    ll before = (ll)(S.at(0) - '0');
    ll after = (ll)(S.at(1) - '0');
    ll diff = after - before;
    for(ll i = 2; i < (ll)(S.length()); i++) {
        ll before = (ll)(S.at(i - 1) - '0');
        ll after = (ll)(S.at(i) - '0');
        if((after - before) != diff) {
            return false;
        }
    }
    return true;
}

void dfs(ll c, ll dig, ll &ans, ll X) {
    if(isArithmetic(c)) {
        if(c >= X) {
            ans = min(ans, c);
        }
    } else {
        return;
    }
    if(dig == 0) {
        return;
    }

    for(ll i = 0; i < 10; i++) {
        dfs(c * 10 + i, dig - 1, ans, X);
    }
    return;
}

int main(){
    ll X;
    cin >> X;
    ll ans = INF;
    dfs(0, 18, ans, X);
    cout << ans << endl;
    return 0;
}