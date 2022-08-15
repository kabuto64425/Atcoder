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

vector<ll> bfs(const Graph &G, ll vertex) {
    // BFS のためのデータ構造
    vector<ll> dist(G.size(), -1); // 全頂点を「未訪問」に初期化
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[vertex] = 0;
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (ll nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    return dist;
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    // 辺の情報
    vector<pair<ll, ll>> edges(N - 1);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    vector<pair<ll, ll>> cd(Q);
    for(pair<ll, ll> &elm : cd) {
        cin >> elm.first >> elm.second;
        elm.first--;
        elm.second--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for(const pair<ll, ll> &edge : edges) {
        G[edge.first].push_back(edge.second);
        G[edge.second].push_back(edge.first);
    }

    vector<ll> distFromZero = bfs(G, 0);
    vector<ll>::iterator iter = max_element(distFromZero.begin(), distFromZero.end());
    size_t indexFarthestFromZero = distance(distFromZero.begin(), iter);

    vector<ll> distFromFarthest = bfs(G, (ll) indexFarthestFromZero);

    for(const pair<ll, ll> &elm : cd) {
        ll d1 = distFromFarthest.at(elm.first);
        ll d2 = distFromFarthest.at(elm.second);
        if(abs(d1 - d2) % 2 == 0) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }

    return 0;
}