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
    ll Q;
    cin >> Q;
    vector<ll> t(Q), x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> t.at(i) >> x.at(i);
    }
    set<ll> s;
    for(ll i = 0; i < 1048576; i++) {
        s.insert(i);
    }
    vector<ll> ans(1048576, -1);
    for(ll i = 0; i < Q; i++) {
        if(t.at(i) == 1) {
            ll j = x.at(i) % 1048576;
            set<ll>::iterator ite = s.lower_bound(j);
            ll k;
            if(ite == s.end()) {
                k = *s.lower_bound(0);
            } else {
                k = *ite;
            }
            s.erase(k);
            ans.at(k) = x.at(i);
        } else {
            cout << ans.at(x.at(i) % 1048576) << endl;
        }
    }
    return 0;
}