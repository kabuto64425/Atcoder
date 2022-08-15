#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<bool> &seen, const vector<ll> &C, vector<ll> &colored, vector<ll> &ans) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    if(colored.at(C.at(v)) == 0) {
        ans.push_back(v + 1);
    }
    colored.at(C.at(v))++;

    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen, C, colored, ans); // 再帰的に探索
    }
    //ここまで
    colored.at(C.at(v))--;
}

int main() {
    // 頂点数と辺数
    ll N;
    cin >> N;
    vector<ll> C(N);
    for(ll &c : C) {
        cin >> c;
    }

    // 辺の情報
    vector<pair<ll, ll>> edges(N - 1);
    for(pair<ll, ll> &p : edges) {
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N - 1; ++i) {
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }

    vector<bool> seen;
    vector<ll> ans;

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    vector<ll> colored(100001, 0);
    dfs(G, 0, seen, C, colored, ans);
    sort(ans.begin(), ans.end());
    for(const ll &x : ans) {
        cout << x << endl;
    }
    return 0;
}