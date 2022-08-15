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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> l(Q), r(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> l.at(i) >> r.at(i);
    }
    dsu d(N + 1);
    for(ll i = 0; i < Q; i++) {
        d.merge(l.at(i) - 1, r.at(i));
    }
    if(d.same(0, N)) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}