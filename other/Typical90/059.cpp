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

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<pair<ll, ll>> &timeStamps, ll &ptr, vector<bool> &seen) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    timeStamps[v].first = ptr;
    ptr++;
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, timeStamps, ptr, seen); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    timeStamps[v].second = ptr;
    ptr++;
    //ここまで
}

int main() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    // 辺の情報
    vector<pair<ll, ll>> edges(M);
    for(ll i = 0 ; i < M; i++) {
        cin >> edges.at(i).first >> edges.at(i).second;
        edges.at(i).first--;
        edges.at(i).second--;
    }

    vector<pair<ll, ll>> queries(Q);
    for(ll i = 0 ; i < Q; i++) {
        cin >> queries.at(i).first >> queries.at(i).second;
        queries.at(i).first--;
        queries.at(i).second--;
    }

    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
    }

    for(ll i = 0; i < Q; i++) {
        vector<pair<ll, ll>> timeStamps(N);
        ll ptr = 0;
        vector<bool> seen;

        // 頂点 0 をスタートとした探索
        seen.assign(N, false); // 全頂点を「未訪問」に初期化
        dfs(G, queries.at(i).first, timeStamps, ptr, seen);
        if(seen.at(queries.at(i).second)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}