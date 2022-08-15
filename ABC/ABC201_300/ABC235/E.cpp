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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> a(M), b(M), c(M);
    for(ll i = 0; i < M; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }
    vector<ll> v(Q), u(Q), w(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> v.at(i) >> u.at(i) >> w.at(i);
    }
    vector<tuple<ll, ll, ll, ll>> vec;
    for(ll i = 0; i < M; i++) {
        vec.push_back({c.at(i), INF, a.at(i), b.at(i)});
    }
    for(ll i = 0; i < Q; i++) {
        vec.push_back({w.at(i), i, u.at(i), v.at(i)});
    }
    sort(ALL(vec));
    dsu d(N);
    vector<bool> ans(Q);
    for(const tuple<ll, ll, ll, ll> &elm : vec) {
        ll x = get<2>(elm) - 1;
        ll y = get<3>(elm) - 1;
        ll queryNum = get<1>(elm);
        if(!d.same(x, y)) {
            if(queryNum == INF) {
                d.merge(x, y);
            } else {
                ans.at(queryNum) = true;
            }
        }
    }
    for(ll i = 0; i < Q; i++) {
        if(ans.at(i)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}