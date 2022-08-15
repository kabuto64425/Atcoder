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

int main(){
    ll N;
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<ll> x(N), y(N), r(N);
    for(ll i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i) >> r.at(i);
    }
    ll c1, c2;
    for(ll i = 0; i < N; i++) {
        if((sx - x.at(i)) * (sx - x.at(i)) + (sy - y.at(i)) * (sy - y.at(i)) == r.at(i) * r.at(i)) {
            c1 = i;
        }
        if((tx - x.at(i)) * (tx - x.at(i)) + (ty - y.at(i)) * (ty - y.at(i)) == r.at(i) * r.at(i)) {
            c2 = i;
        }
    }

    dsu d(N);
    for(ll i = 0; i < N; i++) for(ll j = i + 1 ; j < N; j++) {
        ll dist = (x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j));
        if(dist < abs(r.at(i) - r.at(j)) * abs(r.at(i) - r.at(j))) {
            continue;
        }
        if(dist > abs(r.at(i) + r.at(j)) * abs(r.at(i) + r.at(j))) {
            continue;
        }
        d.merge(i, j);
    }
    if(d.same(c1, c2)) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}