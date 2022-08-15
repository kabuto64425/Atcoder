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
        a.at(i)--;
        b.at(i)--;
    }
    vector<ll> u(Q), v(Q), w(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> u.at(i) >> v.at(i) >> w.at(i);
        u.at(i)--;
        v.at(i)--;
    }
    vector<tuple<ll, ll, ll, ll>> edges(M + Q);
    for(ll i = 0; i < M; i++) {
        get<0>(edges.at(i)) = c.at(i);
        get<1>(edges.at(i)) = a.at(i);
        get<2>(edges.at(i)) = b.at(i);
        get<3>(edges.at(i)) = -1;
    }
    for(ll i = 0; i < Q; i++) {
        get<0>(edges.at(M + i)) = w.at(i);
        get<1>(edges.at(M + i)) = u.at(i);
        get<2>(edges.at(M + i)) = v.at(i);
        get<3>(edges.at(M + i)) = i;
    }
    sort(ALL(edges));
    vector<bool> ans(Q);
    dsu d(N);
    for(ll i = 0; i < M + Q; i++) {
        if(get<3>(edges.at(i)) == -1) {
            if(!d.same(get<1>(edges.at(i)), get<2>(edges.at(i)))) {
                d.merge(get<1>(edges.at(i)), get<2>(edges.at(i)));
            }
        } else {
            if(!d.same(get<1>(edges.at(i)), get<2>(edges.at(i)))) {
                ans.at(get<3>(edges.at(i))) = true;
            } else {
                ans.at(get<3>(edges.at(i))) = false;
            }
        }
    }
    for(ll i = 0; i < Q; i++) {
        cout << (ans.at(i)? "Yes" : "No") << endl;
    }
    return 0;
}