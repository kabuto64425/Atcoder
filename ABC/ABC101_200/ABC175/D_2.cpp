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
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    vector<ll> C(N);
    for(ll i = 0; i < N; i++) {
        cin >> P.at(i);
        P.at(i)--;
    }
    for(ll i = 0; i < N; i++) {
        cin >> C.at(i);
    }

    vector<vector<ll>> next(60, vector<ll>(N));
    vector<vector<ll>> sum(60, vector<ll>(N, 0));
    vector<vector<ll>> m(60, vector<ll>(N, 0));
    for (ll v = 0; v < N; ++v) {
        next[0][v] = P[v];
        sum[0][v] = C[P[v]];
        m[0][v] = C[P[v]];
    }
    for (ll d = 0; d + 1 < 60; ++d) {
        for (ll v = 0; v < N; ++v) {
            next[d+1][v] = next[d][next[d][v]];
            sum[d+1][v] = sum[d][v] + sum[d][next[d][v]];
            m[d+1][v] = max(m[d][v], sum[d][v] + m[d][next[d][v]]);
        }
    }
    ll ans = -INF;
    for(ll i = 0; i < N; i++) {
        ll v = i;
        ll now = 0;
        ll res = -INF;
        for (ll d = 0; d < 60; ++d) {
            if (K & (1LL<<d)) {
                res = max(res, now + m[d][v]);
                now += sum[d][v];
                v = next[d][v];
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}