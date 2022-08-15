#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
    ll N, M;
    cin >> N >> M;
    vector<ll> U(M), V(M);
    for(ll i = 0; i < M ; i++) {
        cin >> U.at(i) >> V.at(i);
        U.at(i)--;
        V.at(i)--;
    }
    if(N != M) {
        cout << 0 << endl;
        return 0;
    }
    dsu d(N);
    vector<ll> e(N);
    for(ll i = 0 ; i < M; i++) {
        if(d.same(U.at(i), V.at(i))) {
            e.at(d.leader(U.at(i)))++;
        } else {
            ll count = e.at(d.leader(U.at(i))) + e.at(d.leader(V.at(i)));
            d.merge(U.at(i), V.at(i));
            e.at(d.leader(U.at(i))) = count + 1;
        }
    }
    for(ll i = 0; i < N; i++) {
        if(d.size(i) != e.at(d.leader(i))) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll gp = d.groups().size();
    mint ans = 1;
    for(ll i = 0; i < gp; i++) {
        ans *= 2;
    }
    cout << ans.val() << endl;
    return 0;
}