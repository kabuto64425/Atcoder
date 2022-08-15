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
    vector<ll> C(N);
    for(ll &c : C) {
        cin >> c;
        c--;
    }
    vector<ll> x(Q), a(Q), b(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i) >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    dsu d(N);
    vector<map<ll, ll>> ans(N);
    for(ll i = 0; i < N; i++) {
        ans.at(i)[C.at(i)] += 1;
    }
    for(ll i = 0; i < Q; i++) {
        if(x.at(i) == 1) {
            if(d.same(a.at(i), b.at(i))) {
                continue;
            }
            ll x = d.leader(a.at(i));
            ll y = d.leader(b.at(i));
            if(d.size(y) > d.size(x)) {
                swap(x, y);
            }
            for(pair<const ll, ll> &elm : ans.at(y)) {
                ans.at(x)[elm.first] += elm.second;
            }
            d.merge(a.at(i), b.at(i));
        } else {
            cout << ans.at(d.leader(a.at(i)))[b.at(i)] << endl;
        }
    }
    return 0;
}