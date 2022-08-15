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

void dfs(ll N, ll current, ll flags, ll &ans) {
    if(current > N) {
        return;
    } else {
        if(flags == 7) {
            ans++;
        }
    }
    dfs(N, current * 10 + 7, flags | 4, ans);
    dfs(N, current * 10 + 5, flags | 2, ans);
    dfs(N, current * 10 + 3, flags | 1, ans);
}

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    dfs(N, 0, 0, ans);
    cout << ans << endl;
    return 0;
}