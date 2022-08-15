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

void dfs(ll x, ll dig, ll flags, ll N, ll &ans) {
    if((flags & 4) && (flags & 2) && (flags & 1) && (x <= N)) {
        ans++;
    }
    if(dig == 0) {
        return;
    }
    dfs(x * 10 + 7, dig - 1, flags | 4, N, ans);
    dfs(x * 10 + 5, dig - 1, flags | 2, N, ans);
    dfs(x * 10 + 3, dig - 1, flags | 1, N, ans);
}

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    dfs(0, 10, 0, N, ans);
    cout << ans << endl;
    return 0;
}