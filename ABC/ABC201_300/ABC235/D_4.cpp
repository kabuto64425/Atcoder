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

void bfs(vector<ll> &dist, const ll a, ll vertex) {
    // BFS のためのデータ構造
    queue<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[vertex] = 0;
    que.push(vertex); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        if(v * a <= 1000000) {
            if(dist[v * a] == -1) {
                dist[v * a] = dist[v] + 1;
                que.push(v * a);
            }
        }

        if(v < 10) {
            continue;
        }
        if(v % 10 == 0) {
            continue;
        }

        string str = to_string(v);
        ll nv = 0;
        ll len = str.length();
        for(ll i = 0; i < len; i++) {
            nv *= 10;
            nv += str.at((i - 1 + len) % len) - '0';
        }
        if(nv <= 1000000) {
            if(dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    return;
}

int main(){
    
    ll a, N;
    cin >> a >> N;

    vector<ll> dist(1000000, -1); // 全頂点を「未訪問」に初期化
    bfs(dist, a, 1);

    cout << dist[N] << endl;
    return 0;
}