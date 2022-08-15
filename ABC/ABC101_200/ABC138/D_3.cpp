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

void dfs(const Graph &G, vector<ll> &ans, ll v = 0, ll pre = -1) {
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        ans.at(nv) += ans.at(v);
        dfs(G, ans, nv, v);
    }
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N - 1), b(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    vector<ll> p(Q), x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> p.at(i) >> x.at(i);
        p.at(i)--;
    }

    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G[a.at(i)].push_back(b.at(i));
        G[b.at(i)].push_back(a.at(i));
    }

    vector<ll> ans(N);
    for(ll i = 0; i < Q; i++) {
        ans.at(p.at(i)) += x.at(i);
    }
    dfs(G, ans);
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}