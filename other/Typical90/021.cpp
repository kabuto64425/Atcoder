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
void dfs(const Graph &G, ll v, map<ll, ll> &timeStampMap, ll &ptr, vector<bool> &seen) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, timeStampMap, ptr, seen); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    timeStampMap[ptr] = v;
    ptr++;
    //ここまで
}

int main() {
    ll N, M;
    cin >> N >> M;

    // 辺の情報
    vector<pair<ll, ll>> edges(M);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
    }

    map<ll, ll> timeStampMap;
    ll ptr = 0;
    vector<bool> seen;

    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    for(ll i = 0; i < N; i++) {
        if(seen.at(i)) {
            continue;
        }
        dfs(G, i, timeStampMap, ptr, seen);
    }

    Graph G2(N);
    for (ll i = 0; i < M; ++i) {
        G2[edges[i].second].push_back(edges[i].first);
    }

    map<ll, ll> timeStampMap2;
    vector<bool> seen2;

    seen2.assign(N, false); // 全頂点を「未訪問」に初期化

    ll ans = 0;

    for(ll i = N - 1; i >= 0; i--) {
        ll v = timeStampMap[i];
        if(seen2.at(v)) {
            continue;
        }
        ll count = 0;
        dfs(G2, v, timeStampMap2, count, seen2);
        ans += count * (count - 1) / 2;
    }

    cout << ans << endl;
    
    return 0;
}