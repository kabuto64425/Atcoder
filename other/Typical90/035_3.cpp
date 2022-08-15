#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

// LCA を求めるライブラリ
struct LCA {
    vector<vector<ll> > parent; // parent[d][v] := 2^d-th parent of v
    vector<ll> depth;
    LCA() { }
    LCA(const Graph &G, ll r = 0) { init(G, r); }
    void init(const Graph &G, ll r = 0) {
        ll V = (ll)G.size();
        ll h = 1;
        while ((1<<h) < V) ++h;
        parent.assign(h, vector<ll>(V, -1));
        depth.assign(V, -1);
        dfs(G, r, -1, 0);
        for (ll i = 0; i+1 < (ll)parent.size(); ++i)
            for (ll v = 0; v < V; ++v)
                if (parent[i][v] != -1)
                    parent[i+1][v] = parent[i][parent[i][v]];
    }
    void dfs(const Graph &G, ll v, ll p, ll d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto e : G[v]) if (e != p) dfs(G, e, v, d+1);
    }
    ll get(ll u, ll v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (ll i = 0; i < (ll)parent.size(); ++i)
            if ( (depth[v] - depth[u]) & (1<<i) )
                v = parent[i][v];
        if (u == v) return u;
        for (ll i = (ll)parent.size()-1; i >= 0; --i) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
};

int main(){
    ll N;
    cin >> N;

    // 辺の情報
    vector<pair<ll, ll>> edges(N - 1);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    ll Q;
    cin >> Q;
    vector<pair<ll , vector<ll>>>  KV(Q);
    for(pair<ll , vector<ll>> &elm : KV) {
        cin >> elm.first;
        elm.second = vector<ll>(elm.first);
        for(ll &v : elm.second) {
            cin >> v;
            v--;
        }
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < (ll) edges.size(); ++i) {
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }

    // LCA ライブラリ
    LCA lca(G);

    for(const pair<ll , vector<ll>> &elm : KV) {
        if(elm.first == 2) {
            // lca
            ll v = lca.get(elm.second.at(0), elm.second.at(1));

            // パスの長さ
            ll len = lca.depth[elm.second.at(0)] + lca.depth[elm.second.at(1)] - 2 * lca.depth[v];

            cout << len << endl;
        } else {
            // lca
            ll v1 = lca.get(elm.second.at(0), elm.second.at(1));

            // パスの長さ
            ll len1 = lca.depth[elm.second.at(0)] + lca.depth[elm.second.at(1)] - 2 * lca.depth[v1];

            // lca
            ll v2 = lca.get(elm.second.at(0), elm.second.at(2));

            // パスの長さ
            ll len2 = lca.depth[elm.second.at(0)] + lca.depth[elm.second.at(2)] - 2 * lca.depth[v2];

            // lca
            ll v3 = lca.get(elm.second.at(1), elm.second.at(2));

            // パスの長さ
            ll len3 = lca.depth[elm.second.at(1)] + lca.depth[elm.second.at(2)] - 2 * lca.depth[v3];

            cout << (len1 + len2 + len3) / 2 << endl;
        }
       
    }

    return 0;
}