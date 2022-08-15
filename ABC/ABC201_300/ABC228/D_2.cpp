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
    set<ll> s;
    ll N = 1048576LL;
    for(ll i = 0; i < N; i++) {
        s.insert(i);
    }
    vector<ll> ans(N, -1);
    
    ll Q;
    cin >> Q;
    vector<ll> t(Q), x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> t.at(i) >> x.at(i);
    }
    for(ll i = 0; i < Q; i++) {
        if(t.at(i) == 1) {
            ll h = x.at(i);
            std::set<ll>::iterator ite = s.lower_bound(h % N);
            ll j = 0;
            if(ite != s.end()) {
                j = *s.lower_bound(h % N);
            } else {
                j = *s.lower_bound(0);
            }
            s.erase(j);
            ans.at(j) = h;
        } else {
            ll h = x.at(i);
            cout << ans.at(h % N) << endl;
        }
    }
    return 0;
}