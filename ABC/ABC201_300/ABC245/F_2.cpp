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

using Graph = vector<vector<ll>>;

void dfs(const Graph &RG, ll v, vector<bool> &seen) {
    seen.at(v) = true;
    for(ll nv : RG[v]) {
        if(seen.at(nv)) {
            continue;
        }
        dfs(RG, nv, seen);
    }
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> U(M), V(M);
    for(ll i = 0; i < M; i++) {
        cin >> U.at(i) >> V.at(i);
    }
    

    vector<bool> flags(N);

    scc_graph graph(N);
    for(ll i = 0; i < M; i++) {
        graph.add_edge(U.at(i) - 1, V.at(i) - 1);
    }
    for(const vector<int> &vec : graph.scc()) {
        if(vec.size() >= 2) {
            for(const ll v : vec) {
                flags.at(v) = true;
            }
        }
    }

    Graph RG(N);
    for(ll i = 0; i < M; i++) {
        RG.at(V.at(i) - 1).push_back(U.at(i) - 1);
    }

    vector<bool> seen(N);

    for(ll i = 0; i < N; i++) {
        if(flags.at(i)) {
            dfs(RG, i, seen);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(seen.at(i)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}