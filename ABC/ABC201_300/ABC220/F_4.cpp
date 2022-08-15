#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

void dfs(Graph &G, ll v, ll pre, vector<ll> &dp, vector<ll> &sub) {
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        dfs(G, nv, v, dp, sub);
        sub[v] += sub[nv];
        dp[v] += dp[nv] + sub[nv];
    }
    sub[v]++;
}

void bfs(const Graph &G, ll N, ll vertex, vector<ll> &sub, vector<ll> &ans) {
    // BFS のためのデータ構造
    queue<ll> que;
    vector<bool> seen(N, false);

    // 初期条件 (頂点 0 を初期ノードとする)
    seen[vertex] = true;
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            if(seen[nv]) {
                continue;// すでに発見済みの頂点は探索しない
            }

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            ans[nv] = ans[v] + N - 2 * sub[nv];
            seen[nv] = true;
            que.push(nv);
        }
    }

    return;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> u(N - 1), v(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> u.at(i) >> v.at(i);
        u.at(i)--;
        v.at(i)--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N - 1; ++i) {
        G[u.at(i)].push_back(v.at(i));
        G[v.at(i)].push_back(u.at(i));
    }
    vector<ll> dp(N);
    vector<ll> sub(N);

    dfs(G, 0, -1, dp, sub);

    vector<ll> ans(N);
    ans.at(0) = dp.at(0);

    bfs(G, N, 0, sub, ans);

    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }

    return 0;
}