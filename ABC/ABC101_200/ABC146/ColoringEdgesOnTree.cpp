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

using Graph = vector<vector<pair<ll, ll>>>;

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, pair<ll, ll> v, vector<ll> &ans, vector<bool> &seen) {
    seen[v.first] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    ll color = 1;
    for(ll i = 0; i < G[v.first].size(); i++) {
        pair<ll, ll> next_v = G[v.first][i];
        if (seen[next_v.first]) continue;
        if(v.second != INF and ans.at(v.second) == color) {
            color++;
        }
        ans.at(next_v.second) = color;
        color++;
        dfs(G, next_v, ans, seen); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    ll N;
    cin >> N;

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    vector<bool> seen;

    vector<ll> ans(N - 1);

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, {0, INF}, ans, seen);
    ll count = *max_element(ans.begin(), ans.end());
    cout << count << endl;
    for(const ll &a : ans) {
        cout << a << endl;
    }
    return 0;
}