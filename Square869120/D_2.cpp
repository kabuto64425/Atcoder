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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

void dfs(const Graph &G, ll v, ll pre, vector<long double> &dp) {
    ll count = 0;
    long double sum = 0;
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        dfs(G, nv, v, dp);
        sum += dp.at(nv);
        count++;
    }
    if(count == 0) {
        dp.at(v) = 0;
    } else {
        dp.at(v) = (sum / (long double)count) + (long double)1;
    }
}

void bfs(const Graph &G, const vector<ll> &d, const vector<long double> &dp, vector<long double> &ans, ll vertex) {
    // BFS のためのデータ構造
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    ans[vertex] = dp.at(vertex);
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            if (ans[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            if(d[v] == 1) {
                ans[nv] = 1 / (long double)(d[nv]) + dp[nv] * (d[nv] - 1) / (long double)(d[nv]);
            } else {
                long double x = ans[v] * d[v] - dp[nv] - 1;
                x /= (d[v] - 1);
                ans[nv] = (long double)(x + 1) / (long double)(d[nv]) + dp[nv] * (d[nv] - 1) / (long double)(d[nv]);
            }

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            que.push(nv);
        }
    }

    return;
}

int main(){
    ll N;
    cin >> N;

    // 辺の情報
    vector<pair<ll, ll>> edges(N - 1);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    Graph G(N);

    for(const pair<ll, ll> &edge : edges) {
        G[edge.first].push_back(edge.second);
        G[edge.second].push_back(edge.first);
    }

    vector<long double> dp(N);
    vector<ll> d(N);
    for(ll i = 0; i < N; i++) {
        d.at(i) = G[i].size();
    }

    dfs(G, 0, -1, dp);

    vector<long double> ans(N, -1);
    bfs(G, d, dp, ans, 0);

    for(ll i = 0; i < N; i++) {
        cout << fixed << setprecision(20) << ans.at(i) << endl;
    }

    return 0;
}