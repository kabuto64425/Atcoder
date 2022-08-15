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
ll dfs(const Graph &G, ll v, vector<bool> &seen) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    //ここまで
    seen[v] = true; // v を訪問済にする

    ll mi = INF;
    ll ma = 0;

    ll count = 0;

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        count++;
        ll x = dfs(G, next_v, seen);
        mi = min(mi, x);
        ma = max(ma, x);
    }
    if(count == 0) {
        return 1;
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    return mi + ma + 1;
    //ここまで
}

int main() {
    ll N;
    cin >> N;

    // 辺の情報
    ll M = N - 1;
    vector<pair<ll, ll>> edges(M);
    for(ll i= 0; i < M; i++) {
        ll m;
        cin >> m;
        edges.at(i) = {i + 2, m};
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first - 1].push_back(edges[i].second - 1);
        G[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    vector<pair<ll, ll>> salary(N);
    ll ptr = 0;
    vector<bool> seen;

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    cout << dfs(G, 0, seen) << endl;
    return 0;
}