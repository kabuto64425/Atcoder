#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

// セグメント木の二項演算 (XOR 和)
ll op(ll a, ll b) {
    return a ^ b;
}

// 単位元 (今回は 0)
ll e() {
    return 0;
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    segtree<ll, op, e> seg(A);
    for(ll i = 0; i < Q; i++) {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            x--;
            // 元の値
            int v = seg.get(x);

            // 変更後の値
            v ^= y;

            // 更新
            seg.set(x, v);
        } else {
            x--;
            cout << seg.prod(x, y) << endl;
        }
    }
    return 0;
}