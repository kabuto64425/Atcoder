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

using Graph = vector<vector<ll>>;

int main(){
    ll N;
    cin >> N;
    vector<ll> X(N);
    vector<ll> C(N);
    for(ll &x : X) {
        cin >> x;
        x--;
    }
    for(ll i = 0; i < N; i++) {
        cin >> C.at(i);
    }
    scc_graph graph(N);

    for(ll i = 0; i < N; i++) {
        graph.add_edge(X[i], i);
    }

    vector<vector<int>> scc = graph.scc();

    ll ans = 0;
    for(auto v : scc) {
        if(v.size() >= 2) {
            ll mini = INF;
            for(ll i = 0; i < v.size(); i++) {
                chmin(mini, C.at(v.at(i)));
            }
            ans += mini;
        }
    }
    
    cout << ans << endl;

    return 0;
}