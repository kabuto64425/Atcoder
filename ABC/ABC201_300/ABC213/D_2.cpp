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

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<bool> &seen, queue<ll> &ans) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    ans.push(v);
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen, ans); // 再帰的に探索
        ans.push(v);
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    
    //ここまで
}

int main() {
    ll N;
    cin >> N;

    // 辺の情報
    vector<pair<ll, ll>> edges(N - 1);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N - 1; ++i) {
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }

    for(ll i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
    }

    vector<bool> seen;

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    queue<ll> ans;
    dfs(G, 0, seen, ans);
    
    while(!ans.empty()) {
        cout << ans.front() + 1 << endl;
        ans.pop();
    }
    return 0;
}