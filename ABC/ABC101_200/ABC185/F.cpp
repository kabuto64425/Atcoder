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

ll op(ll a, ll b) {
    return a ^ b;
}

ll e() {
    return 0;
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    segtree<ll, op, e> seg(N);
    for(ll i = 0; i < N; i++) {
        seg.set(i, A.at(i));
    }

    vector<ll> T(Q), X(Q), Y(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> T.at(i) >> X.at(i) >> Y.at(i);
    } 

    for(ll i = 0; i < Q; i++) {
        if(T.at(i) == 1) {
            seg.set(X.at(i) - 1, seg.get(X.at(i) - 1) ^ Y.at(i));
        } else {
            cout << seg.prod(X.at(i) - 1, Y.at(i)) << endl;
        }
    }

    return 0;
}