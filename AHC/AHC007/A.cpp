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

const ll N = 400;
const ll M = 1995;

int main(){
    vector<ll> x(N), y(N);
    vector<ll> u(M), v(M);
    for(ll i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i);
    }
    for(ll i = 0; i < M; i++) {
        cin >> u.at(i) >> v.at(i);
    }
    dsu d(N);
    for(ll i = 0; i < M; i++) {
        ll length;
        cin >> length;
        if(d.same(u.at(i), v.at(i))) {
            cout << 0 << endl;
        } else {
            d.merge(u.at(i), v.at(i));
            cout << 1 << endl;
        }
    }
    return 0;
}