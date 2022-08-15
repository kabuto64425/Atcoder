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

void dfs(ll rest, ll A, ll B, ll C, vector<ll> &l, ll &ans, ll la, ll lb, ll lc, ll current) {
    if(rest == 0) {
        if(la > 0 and lb > 0 and lc > 0) {
            ans = min(ans, abs(A - la) + abs(B - lb) + abs(C - lc) + current - 30);
        }
        return;
    }
    dfs(rest - 1, A, B, C, l, ans, la + l.at(rest - 1), lb, lc, current + 10);
    dfs(rest - 1, A, B, C, l, ans, la, lb + l.at(rest - 1), lc, current + 10);
    dfs(rest - 1, A, B, C, l, ans, la, lb, lc + l.at(rest - 1), current + 10);
    dfs(rest - 1, A, B, C, l, ans, la, lb, lc, current);
}

int main(){
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<ll> l(N);
    for(ll i = 0; i < N; i++) {
        cin >> l.at(i);
    }
    ll ans = INF;
    dfs(N, A, B, C, l, ans, 0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}