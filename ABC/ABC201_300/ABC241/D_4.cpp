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
    vector<ll> c(Q), x(Q), k(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> c.at(i);
        if(c.at(i) == 1) {
            cin >> x.at(i);
        } else {
            cin >> x.at(i) >> k.at(i);
        }
    }
    multiset<ll> ms;
    for(ll i = 0; i < Q; i++) {
        if(c.at(i) == 1) {
            ms.insert(x.at(i));
        } else if(c.at(i) == 2) {
            auto ite = ms.upper_bound(x.at(i));
            bool is_ok = true;
            for(ll j = 0; j < k.at(i); j++) {
                if(ite == ms.begin()) {
                    is_ok = false;
                    break;
                }
                ite--;
            }
            if(is_ok) {
                cout << *ite << endl;
            } else {
                cout << -1 << endl;
            }
        } else if(c.at(i) == 3) {
            auto ite = ms.lower_bound(x.at(i));
            bool is_ok = true;
            for(ll j = 0; j < k.at(i) - 1; j++) {
                if(ite == ms.end()) {
                    is_ok = false;
                    break;
                }
                ite++;
            }
            if(is_ok and ite != ms.end()) {
                cout << *ite << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}