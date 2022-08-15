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

set<pair<ll, ll>> s;

void dfs(const Graph &G, const vector<ll> &H, ll v, ll pre, vector<ll> &ans) {
    //seen.at(v) = true;
    for(ll next_v : G[v]) {
        if(s.count({max(next_v, v), min(next_v, v)})) {
            continue;
        }
        if(H[v] > H[next_v]) {
            ans.at(next_v) = max(ans.at(next_v), ans.at(v) + (H.at(v) - H.at(next_v)));
        } else if(H[v] < H[next_v]) {
            ans.at(next_v) = max(ans.at(next_v), ans.at(v) - (H.at(next_v) - H.at(v)) * 2);
        } else {
            ans.at(next_v) = max(ans.at(next_v), ans.at(v));
        }
        s.insert({max(next_v, v), min(next_v, v)});
        dfs(G, H, next_v, v, ans);
    }
}

int main(){
    // 頂点数と辺数
    ll N, M;
    cin >> N >> M;

    vector<ll> H(N);
    for(ll i = 0; i < N; i++) {
        cin >> H.at(i);
    }

    vector<ll> U(M), V(M);
    for(ll i = 0; i < M; i++) {
        cin >> U.at(i) >> V.at(i);
        U.at(i)--;
        V.at(i)--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[U.at(i)].push_back(V.at(i));
        G[V.at(i)].push_back(U.at(i));
    }
    vector<ll> ans(N, -INF);
    ans.at(0) = 0;
    vector<bool> seen(N, false);
    dfs(G, H, 0, -1, ans);
    return 0;
}