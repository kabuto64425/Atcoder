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

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<bool> &seen, vector<ll> &timestamp, ll &ptr) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    timestamp.at(v) = ptr;
    ptr++;
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen, timestamp, ptr); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    //ここまで
}

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

    vector<bool> seen(N, false);
    vector<ll> timestamp(N, 0);
    ll ptr = 0;

    dfs(G, 0, seen, timestamp, ptr);


    // LCA ライブラリ
    LCA lca(G);

    for(const pair<ll , vector<ll>> &elm : KV) {
        vector<pair<ll, ll>> vec(elm.first);
        for(ll i = 0; i < elm.first; i++) {
            vec.at(i).first = timestamp.at(elm.second.at(i));
            vec.at(i).second = elm.second.at(i);
        }

        sort(vec.begin(), vec.end());

        ll len = 0;

        for(ll i = 0; i < elm.first; i++) {
            // lca
            ll v = lca.get(vec.at(i).second, vec.at((i + 1) % elm.first).second);
            len += lca.depth[vec.at(i).second] + lca.depth[vec.at((i + 1) % elm.first).second] - 2 * lca.depth[v];
        }

        cout << len / 2 << endl;
    }

    return 0;
}