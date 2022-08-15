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
    ll Q;
    cin >> Q;
    vector<ll> T(Q), X(Q), Y(Q), V(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> T.at(i) >> X.at(i) >> Y.at(i) >> V.at(i);
        X.at(i)--;
        Y.at(i)--;
    }

    vector<ll> sum(N - 1, 0);
    for(ll i = 0; i < Q; i++) {
        if(T.at(i) == 0) {
            sum.at(X.at(i)) = V.at(i);
        }
    }

    vector<ll> pot(N, 0);
    for(ll i = 0; i < N - 1; i++) {
        pot.at(i + 1) = sum.at(i) - pot.at(i);
    }

    set<ll> s;
    for(ll i = 0; i < N ; i++) {
        s.insert(i);
    }

    dsu d(N);

    for(ll i = 0; i < Q; i++) {
        if(T.at(i) == 0) {
            s.erase(X.at(i));
            d.merge(X.at(i), Y.at(i));
        } else if(T.at(i) == 1) {
            if(d.same(X.at(i), Y.at(i))) {
                ll d = V.at(i) - pot.at(X.at(i));
                if(X.at(i) % 2 == Y.at(i) % 2) {
                    cout << pot.at(Y.at(i)) + d << endl;
                } else {
                    cout << pot.at(Y.at(i)) - d << endl;
                }
            } else {
                cout << "Ambiguous" << endl;
            }
        }
    }
    return 0;
}