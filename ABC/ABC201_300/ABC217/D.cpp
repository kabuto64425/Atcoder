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
    ll L, Q;
    cin >> L >> Q;
    set<ll> s;
    s.insert(0);
    s.insert(L);
    for(ll q = 0; q < Q; q++) {
        ll c, x;
        cin >> c >> x;
        if(c == 1) {
            s.insert(x);
        } else if(c == 2) {
            set<ll>::iterator ite = s.lower_bound(x);
            ll i = *ite;
            ite--;
            ll j = *ite;
            cout << i - j << endl;
        }
    }
    
    return 0;
}