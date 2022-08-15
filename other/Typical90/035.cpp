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
void dfs(const Graph &G, ll v, vector<bool> &seen, vector<ll> &dp, stack<ll> &trace) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    trace.push(v);
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen, dp, trace); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    trace.pop();
    if(!trace.empty()) {
        ll prev_v = trace.top();
        dp.at(prev_v) += dp.at(v);
    }
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
    for (ll i = 0; i < edges.size(); ++i) {
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }

    for(const pair<ll , vector<ll>> &elm : KV) {
        vector<ll> dp(N, 0);
        for(const ll &v : elm.second) {
            dp.at(v) += 1;
        }
        vector<bool> seen(N, false);
        stack<ll> trace;
        dfs(G, 0, seen, dp, trace);
        ll ans = 0;
        for(const ll &d : dp) {
            if(d >= 1 and d <= elm.first - 1) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}