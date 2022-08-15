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

// Rerooting
// https://youtu.be/zG1L4vYuGrg?t=7092
// TODO: vertex info, edge info
struct Rerooting {
    struct DP {
        ll depth = 0;
        // 部分木の頂点の数
        ll sub = 0;
        DP() {}
        // 部分木を合成（マージ）するときの処理
        DP operator+(const DP& a) const {
            // edit here
            DP res = DP(*this);
            res.depth = max(res.depth, a.depth);
            res.sub = res.sub + a.sub;
            return res;
        }
        // マージされた部分木を親に渡すときの処理
        // 最も子どもの頂点であっても、そこから更に仮想の子がいるとして
        // 仮想の子からaddRootの処理が行われるため注意。
        // 仮想の子から最も子どもの頂点にaddRootしているかどうかは、
        // res.sub == 0 であるかどうかで判定できる。
        DP addRoot() const {
            // edit here
            DP res = DP(*this);
            if(res.sub != 0) {
                res.depth++;
            }
            res.sub++;
            return res;
        }
    };
    
    int n;
    vector<vector<int>> to;
    vector<vector<DP>> dp;
    vector<DP> ans;
    Rerooting(int n=0):n(n),to(n),dp(n),ans(n) {}
    void addEdge(int a, int b) {
        to[a].push_back(b);
        to[b].push_back(a);
    }
    void init() {
        dfs(0);
        bfs(0);
    }
  
    DP dfs(int v, int p=-1) {
        DP dpSum;
        dp[v] = vector<DP>(to[v].size());
        REP(i,to[v].size()) {
            int u = to[v][i];
            if (u == p) continue;
            dp[v][i] = dfs(u,v);
            dpSum = dpSum + dp[v][i];
        }
        return dpSum.addRoot();
    }
    void bfs(int v, const DP& dpP=DP(), int p=-1) {
        int deg = to[v].size();
        REP(i,deg) if (to[v][i] == p) dp[v][i] = dpP;
    
        vector<DP> dpSumL(deg+1);
        REP(i,deg) dpSumL[i+1] = dpSumL[i] + dp[v][i];
        vector<DP> dpSumR(deg+1);
        for (int i = deg-1; i >= 0; --i)
            dpSumR[i] = dpSumR[i+1] + dp[v][i];
        ans[v] = dpSumL[deg].addRoot();
    
        REP(i,deg) {
            int u = to[v][i];
            if (u == p) continue;
            DP d = dpSumL[i] + dpSumR[i+1];
            bfs(u, d.addRoot(), v);
        }
    }
};

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

    Rerooting rerooting(N);
    for (ll i = 0; i < edges.size(); ++i) {
        rerooting.addEdge(edges[i].first, edges[i].second);
    }
    rerooting.init();
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ans = max(ans, rerooting.ans.at(i).depth);
    }
    cout << ans + 1 << endl;
    return 0;
}