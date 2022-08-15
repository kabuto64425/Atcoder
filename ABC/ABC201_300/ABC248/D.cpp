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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ll Q;
    cin >> Q;
    vector<ll> L(Q), R(Q), X(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> L.at(i) >> R.at(i) >> X.at(i);
    }
    vector<vector<ll>> v(220000);
    for(ll i = 0; i < N; i++) {
        v.at(A.at(i)).push_back(i + 1);
    }
    for(ll i = 0; i < Q; i++) {
        ll a = lower_bound(ALL(v.at(X.at(i))), L.at(i)) - v.at(X.at(i)).begin();
        ll b = upper_bound(ALL(v.at(X.at(i))), R.at(i)) - v.at(X.at(i)).begin();
        cout << b - a << endl;
    }
    return 0;
}