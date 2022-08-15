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

using S = ll;
using F = ll;
S op(S a, S b){
    return max(a, b);
}
S e(){
    return 0;
}

S mapping(F l, S r) {
    return max(l, r);
}
F composition(F l, F r) {
    return max(l, r);
}
F id() {
    return 0;
}

int main(){
    ll W, N;
    cin >> W >> N;
    vector<pair<ll, ll>> LR(N);
    for(pair<ll, ll> &lr : LR) {
        cin >> lr.first >> lr.second;
        lr.first--;
        lr.second--;
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(W);
    REP(i, W) { seg.set(i, 0); }

    for(const pair<ll, ll> &lr : LR) {
        ll m = seg.prod(lr.first, lr.second + 1);
        m += 1;
        cout << m << endl;
        seg.apply(lr.first, lr.second + 1, m);
    }

    return 0;
}