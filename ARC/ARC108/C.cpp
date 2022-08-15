#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<pair<ll, ll>>>;

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<ll> &ans, vector<bool> &seen) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v.first]) continue; // next_v が探索済だったらスルー
        if(ans[next_v.first] == 0) {
            if(ans[v] != next_v.second) {
                ans[next_v.first] = next_v.second;
            } else {
                ans[next_v.first] = (next_v.second == 1)? 2 : 1;
            }
        }
        dfs(G, next_v.first, ans, seen); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    ll N, M;
    cin >> N >> M;

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        ll a, b, label;
        cin >> a >> b >> label;
        a--;
        b--;
        G[a].push_back({b, label});
        G[b].push_back({a, label});
    }

    vector<ll> ans(N, 0);
    ans[0] = 1;
    vector<bool> seen;

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, ans, seen);
    for(const ll &a : ans) {
        cout << a << endl;
    }
    return 0;
}