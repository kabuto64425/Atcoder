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

int main(){
    ll N, X, M;
    cin >> N >> X >> M;

    vector<vector<ll>> next(60, vector<ll>(M));
    vector<vector<ll>> sum(60, vector<ll>(M, 0));
    for (ll v = 0; v < M; ++v) {
        next[0][v] = v * v  % M;
        sum[0][v] = v;
    }
    for (ll d = 0; d + 1 < 60; ++d) {
        for (ll v = 0; v < M; ++v) {
            next[d+1][v] = next[d][next[d][v]];
            sum[d+1][v] = sum[d][v] + sum[d][next[d][v]];
        }
    }
    ll v = X;
    ll ans = 0;
    for (ll d = 0; d < 60; ++d) {
        if (N & (1LL<<d)) {
            ans += sum[d][v];
            v = next[d][v];
        }
    }
    cout << ans << endl;
    return 0;
}