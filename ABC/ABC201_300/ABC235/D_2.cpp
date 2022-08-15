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

void bfs(vector<ll> &dist, ll vertex, ll a) {
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

        if(v >= 10 and v % 10 != 0) {
            string s = to_string(v);
            ll y = 0;
            ll dig = s.length();
            for(ll i = 0; i < dig; i++) {
                ll j = (i - 1 + dig) % dig;
                y *= 10;
                y += (ll)(s.at(j) - '0');
            }
            if(dist[y] == -1) {
                dist[y] = dist[v] + 1;
                que.push(y);
            }
        }
    }

    return;
}

int main(){
    ll a, N;
    cin >> a >> N;

    string s = to_string(N);
    ll y = 0;
    ll dig = s.length();
    for(ll i = 0; i < dig; i++) {
        ll j = (i - 1 + dig) % dig;
        y *= 10;
        y += (ll)(s.at(j) - '0');
    }
    vector<ll> dist(1100000, -1); // 全頂点を「未訪問」に初期化
    bfs(dist, 1, a);

    cout << dist.at(N) << endl;

    return 0;
}