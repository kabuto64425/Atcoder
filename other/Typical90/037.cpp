#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

// セグメント木の二項演算 (XOR 和)
ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return -INF;
}

int main(){
    ll W, N;
    cin >> W >> N;
    vector<tuple<ll, ll, ll>> LRV(N);
    for(tuple<ll, ll, ll> &lrv : LRV) {
        cin >> get<0>(lrv) >> get<1>(lrv) >> get<2>(lrv);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(11000, -INF));
    dp.at(0).at(0) = 0;

    for(ll i = 1; i <= N; i++) {
        segtree<ll, op, e> seg(dp.at(i - 1));
        ll l = get<0>(LRV.at(i - 1));
        ll r = get<1>(LRV.at(i - 1));
        ll v = get<2>(LRV.at(i - 1));
        for(ll w = 0; w <= 10000; w++) {
            dp.at(i).at(w) = max(dp.at(i).at(w), dp.at(i- 1).at(w));

            if(w - l >= 0) {
                ll m = seg.prod(max(w - r, 0LL), w - l + 1);
                if(m != -INF) {
                    dp.at(i).at(w) = max(dp.at(i).at(w), m + v);
                }
            }
        }
    }
    if(dp.at(N).at(W) == -INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp.at(N).at(W) << endl;
    return 0;
}