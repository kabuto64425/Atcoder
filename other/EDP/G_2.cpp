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

ll recur(ll v, const Graph &G, vector<ll> &dp) {
    if(dp.at(v) != -1) {
        return dp.at(v);
    }
    ll res = 0;
    for(ll nv : G.at(v)) {
        chmax(res, recur(nv, G, dp) + 1);
    }
    return dp.at(v) = res;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> x(M), y(M);
    for(ll i = 0; i < M; i++) {
        cin >> x.at(i) >> y.at(i);
    }

    Graph G(N);
    for(ll i = 0; i < M; i++) {
        G[x.at(i) - 1].push_back(y.at(i) - 1);
    }

    vector<ll> dp(N, -1);
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        chmax(ans, recur(i, G, dp));
    }
    cout << ans << endl;
    return 0;
}