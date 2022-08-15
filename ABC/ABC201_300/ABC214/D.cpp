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

bool sort_by(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
    return get<2>(a) < get<2>(b);
}

int main(){
    ll N;
    cin >> N;

    // 辺の情報
    vector<tuple<ll, ll, ll>> edges(N - 1);
    for(tuple<ll, ll, ll> &edge : edges) {
        cin >> get<0>(edge) >> get<1>(edge) >> get<2>(edge);
        get<0>(edge)--;
        get<1>(edge)--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < (ll)edges.size(); ++i) {
        G[get<0>(edges[i])].push_back(get<1>(edges[i]));
        G[get<1>(edges[i])].push_back(get<0>(edges[i]));
    }

    vector<ll> dp(N, 1);
    vector<bool> seen(N, false);
    stack<ll> trace;

    sort(edges.begin(), edges.end(), sort_by);

    ll ans = 0;

    dsu d(N);
    for(ll i = 0; i < N - 1; i++) {
        tuple<ll, ll, ll> edge = edges.at(i);
        ans += ((ll)d.size(get<0>(edge)) * (ll)d.size(get<1>(edge)) * get<2>(edge));
        d.merge(get<0>(edge), get<1>(edge));
    }

    cout << ans << endl;

    return 0;
}