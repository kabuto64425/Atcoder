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
    ll Q;
    cin >> Q;
    vector<ll> t(Q), x(Q), c(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> t.at(i);
        if(t.at(i) == 1) {
            cin >> x.at(i);
        }else if(t.at(i) == 2) {
            cin >> x.at(i) >> c.at(i);
        }
    }
    map<ll, ll> m;
    set<ll> s;
    for(ll i = 0; i < Q; i++) {
        if(t.at(i) == 1) {
            if(!s.count(x.at(i))) {
                s.insert(x.at(i));
            }
            m[x.at(i)]++;
        } else if(t.at(i) == 2) {
            m[x.at(i)] = m[x.at(i)] - min(m[x.at(i)], c.at(i));
            if(m[x.at(i)] == 0) {
                s.erase(x.at(i));
            }
        } else if(t.at(i) == 3) {
            ll mi = *s.begin();
            auto ite = s.end();
            ite--;
            ll ma = *ite;
            cout << ma - mi << endl;
        }
    }
    return 0;
}