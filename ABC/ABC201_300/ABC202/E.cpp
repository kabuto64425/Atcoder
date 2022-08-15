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

int dists[200001][200001];

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<pair<ll, ll>> &timeStamps, ll &ptr, vector<bool> &seen, ll dist) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    timeStamps[v].first = ptr;
    ptr++;
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, timeStamps, ptr, seen, dist + 1); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    timeStamps[v].second = ptr;
    ptr++;
    //ここまで
}

int main() {
    ll N;
    cin >> N;
    vector<ll> P(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> P.at(i);
        P.at(i)--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 1; i < N; ++i) {
        G[P.at(i - 1)].push_back(i);
        G[i].push_back(P.at(i - 1));
    }

    vector<pair<ll, ll>> timeStamps(N);
    ll ptr = 0;
    vector<bool> seen;

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, timeStamps, ptr, seen, 0);
    // 結果出力 (各頂点の行きがけのタイムスタンプと帰りがけのタイムスタンプを出力(行きがけ, 帰りがけ))
    for (ll v = 0; v < N; ++v) cout << v << ": " << timeStamps[v].first << ", " << timeStamps[v].second << endl;
    /*
        0: 0, 13
        1: 1, 6
        2: 7, 12
        3: 2, 3
        4: 4, 5
        5: 8, 9
        6: 10, 11
    */
    return 0;
}