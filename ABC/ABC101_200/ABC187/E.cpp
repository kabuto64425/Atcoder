#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfsDepth(const Graph &G, ll v, vector<ll> &depth, vector<bool> &seen, ll d) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    depth[v] = d;
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfsDepth(G, next_v, depth, seen, d + 1); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    
    //ここまで
}

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<ll> &ans, vector<bool> &seen) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        ans[next_v] += ans[v];
        dfs(G, next_v, ans, seen); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    
    //ここまで
}

int main() {
    // 頂点数
    ll N;
    cin >> N;

    // 辺の情報
    vector<pair<ll, ll>> edges(N - 1);
    for(auto &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    ll Q;
    cin >> Q;
    vector<tuple<ll, ll, ll>> tex(Q);
    for(auto &elm : tex) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N - 1; ++i) {
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }

    vector<ll> depth(N);

    vector<bool> seenDepth;
    // 頂点 0 をスタートとした探索
    seenDepth.assign(N, false); // 全頂点を「未訪問」に初期化
    dfsDepth(G, 0, depth, seenDepth, 0);

    vector<ll> ans(N, 0);
    for(ll i = 0; i < Q; i++) {
        const tuple<ll, ll, ll> &elm = tex.at(i);
        ll a = edges.at(get<1>(elm) - 1).first;
        ll b = edges.at(get<1>(elm) - 1).second;
        if(depth.at(b) > depth.at(a)) {
            if(get<0>(elm) == 1) {
                ans.at(0) += get<2>(elm);
                ans.at(b) -= get<2>(elm);
            } else {
                ans.at(b) += get<2>(elm);
            }
        } else {
            if(get<0>(elm) == 2) {
                ans.at(0) += get<2>(elm);
                ans.at(a) -= get<2>(elm);
            } else {
                ans.at(a) += get<2>(elm);
            }
        }
        
    }

    vector<bool> seen;

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, ans, seen);
    for(const ll &elm : ans) {
        cout << elm << endl;
    }
    return 0;
}