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
    vector<ll> query(Q), x(Q), k(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> query.at(i);
        if(query.at(i) == 1) {
            cin >> x.at(i);
        } else {
            cin >> x.at(i) >> k.at(i);
        }
    }
    multiset<ll> A;
    for(ll t = 0; t < Q; t++) {
        if(query.at(t) == 1) {
            A.insert(x.at(t));
        } else if(query.at(t) == 2) {
            multiset<ll>::iterator ite = A.upper_bound(x.at(t));
            bool flag = true;
            for(ll i = 0; i < k.at(t); i++) {
                if(ite == A.begin()) {
                    flag = false;
                    break;
                }
                ite--;
            }
            if(flag) {
                cout << *ite << endl;
            } else {
                cout << -1 << endl;
            }
        } else if(query.at(t) == 3) {
            multiset<ll>::iterator ite = A.lower_bound(x.at(t));
            bool flag = true;
            for(ll i = 0; i < k.at(t) - 1; i++) {
                if(ite == A.end()) {
                    flag = false;
                    break;
                }
                ite++;
            }
            if(flag and ite != A.end()) {
                cout << *ite << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}