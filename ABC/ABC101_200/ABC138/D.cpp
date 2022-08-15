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
void dfs(const Graph &G, ll v, vector<bool> &seen, stack<ll> &trace, vector<ll> &ans) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    if(!trace.empty()) {
        ll prev = trace.top();
        ans.at(v) += ans.at(prev);
    }
    trace.push(v);
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen, trace, ans); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    trace.pop();
    //ここまで
}

int main() {
    // 頂点数と辺数
    ll N, Q;
    cin >> N >> Q;
    // 辺の情報
    vector<pair<ll, ll>> edges(N - 1);
    for(pair<ll, ll> &eadge : edges) {
        cin >> eadge.first >> eadge.second;
        eadge.first--;
        eadge.second--;
    }

    vector<pair<ll, ll>> px(Q);
    for(pair<ll, ll> &elm : px) {
        cin >> elm.first >> elm.second;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N - 1; ++i) {
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }

    vector<pair<ll, ll>> timeStamps(N);
    ll ptr = 0;
    vector<bool> seen;
    stack<ll> trace;
    vector<ll> ans(N, 0);
    for(const pair<ll, ll> &elm : px) {
        ans.at(elm.first - 1) += elm.second;
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, seen, trace, ans);
    for(const ll elm : ans) {
        cout << elm << endl;
    }
    return 0;
}