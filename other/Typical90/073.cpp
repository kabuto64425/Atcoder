#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, const vector<char> &c, ll v, ll pre, vector<vector<mint>> &dp) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    
    //ここまで

    mint a = 1;
    mint b = 1;
    mint both = 1;

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if(next_v == pre) {
            continue;
        }
        dfs(G, c, next_v, v, dp); // 再帰的に探索
        a *= (dp[next_v][0] + dp[next_v][2]);
        b *= (dp[next_v][1] + dp[next_v][2]);
        both *= (dp[next_v][0] + dp[next_v][1] + 2 * dp[next_v][2]);
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    if(c.at(v) == 'a') {
        dp[v][0] = a;
        dp[v][2] = both - a;
    }
    if(c.at(v) == 'b') {
        dp[v][1] = b;
        dp[v][2] = both - b;
    }
    //ここまで
}

int main() {
    ll N;
    cin >> N;
    vector<char> c(N);
    for(ll i = 0; i < N; i++) {
        cin >> c.at(i);
    }
    vector<ll> a(N - 1), b(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G[a.at(i)].push_back(b.at(i));
        G[b.at(i)].push_back(a.at(i));
    }
    vector<vector<mint>> dp(N, vector<mint>(3));
    dfs(G, c, 0, -1, dp);
    cout << dp.at(0).at(2).val() << endl;
    return 0;
}