#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;
/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
 */
vector<int> topo_sort(const Graph &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (ll e : G[i]) {
            ind[e]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.top();
        ans.push_back(now);
        que.pop();
        for (ll e : G[now]) {
            ind[e]--;
            if (ind[e] == 0) {
                que.push(e);
            }
        }
    }
    return ans;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(M);
    for(ll i = 0; i < M; i++) {
        cin >> AB.at(i).first >> AB.at(i).second;
        AB.at(i).first--;
        AB.at(i).second--;
    }
    Graph G(N);
    for(ll i = 0; i < M; i++) {
        G[AB.at(i).first].push_back(AB.at(i).second);
    }

    vector<int> ans = topo_sort(G);
    if(ans.size() != N) {
        cout << -1 << endl;
        return 0;
    }
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) + 1 << " ";
    }
    cout << endl;

    return 0;
}