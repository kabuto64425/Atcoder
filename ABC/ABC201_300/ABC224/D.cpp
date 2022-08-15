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

void bfs(const Graph &G, map<string, ll> &dist, string vertex, ll vSpace) {
    // BFS のためのデータ構造
    queue<string> que;
    queue<ll> spaceQue;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[vertex] = 0;
    que.push(vertex); // 0 を橙色頂点にする
    spaceQue.push(vSpace);
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        string v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        ll space = spaceQue.front();
        spaceQue.pop();
        for (ll cur : G[space]) {
            string nv = v;
            swap(nv.at(space), nv.at(cur));
            if (dist.count(nv)) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
            spaceQue.push(cur);
        }
    }

    return;
}

int main(){
    
    ll M;
    cin >> M;

    vector<ll> u(M), v(M);
    for(ll i = 0; i < M; i++) {
        cin >> u.at(i) >> v.at(i);
        u.at(i)--;
        v.at(i)--;
    }
    vector<ll> p(8);
    for(ll i = 0; i < 8; i++) {
        cin >> p.at(i);
    }

    Graph G(9);
    for(ll i = 0; i < M; i++) {
        G.at(u.at(i)).push_back(v.at(i));
        G.at(v.at(i)).push_back(u.at(i));
    }

    map<string, ll> dist;

    string vertex = "999999999";
    for(ll i = 0; i < 8; i++) {
        vertex.at(p.at(i) - 1) = (char)((i + 1) + '0');
    }
    ll vSpace = 0;
    for(ll i = 0; i < 9; i++) {
        if(vertex.at(i) == '9') {
            vSpace = i;
            break;
        }
    }

    bfs(G, dist, vertex, vSpace);

    if(!dist.count("123456789")) {
        cout << -1 << endl;
        return 0;
    }

    cout << dist["123456789"] << endl;
    return 0;
}