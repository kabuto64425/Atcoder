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
    vector<ll> L(Q), R(Q), T(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> L.at(i) >> R.at(i) >> T.at(i);
    }
    vector<ll> ans(N);
    for(ll i = 0; i < Q; i++) {
        for(ll j = L.at(i) - 1; j <= R.at(i) - 1; j++) {
            ans.at(j) = T.at(i);
        }
    }
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
    return 0;
}