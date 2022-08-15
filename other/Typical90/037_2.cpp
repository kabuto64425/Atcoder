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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return -1;
}

int main(){
    ll W, N;
    cin >> W >> N;
    vector<ll> L(N), R(N), V(N);
    for(ll i = 0; i < N; i++) {
        cin >> L.at(i) >> R.at(i) >> V.at(i);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, -1));
    dp.at(0).at(0) = 0;
    segtree<ll, op, e> seg(W + 1);
    seg.set(0, 0);
    for(ll i = 1; i <= W; i++) {
        seg.set(i, -1);
    }
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= W; j++) {
            if(dp.at(i - 1).at(j) != -1) {
                chmax(dp.at(i).at(j), dp.at(i - 1).at(j));
            }
            ll left = j - R.at(i - 1);
            ll right = j - L.at(i - 1) + 1;
            if(right >= 0) {
                ll x = seg.prod(max(left, 0LL), right);
                if(x != -1) {
                    chmax(dp.at(i).at(j), x + V.at(i - 1));
                }
            }
        }
        for(ll j = 0; j <= W; j++) {
            seg.set(j, dp.at(i).at(j));
        }
    }
    cout << dp.at(N).at(W) << endl;
    return 0;
}