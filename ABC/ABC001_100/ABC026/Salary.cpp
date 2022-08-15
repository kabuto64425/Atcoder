#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

using Graph = vector<vector<int>>;

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

// 深さ優先探索
ll dfs(const Graph &G, ll v) {
    if(G[v].empty()) {
        return 1;
    }
    ll ma = 0;
    ll mi = INF;
    for (auto next_v : G[v]) {
        ll res = dfs(G, next_v); // 再帰的に探索
        ma = max(ma, res);
        mi = min(mi, res);
    }
    return ma + mi + 1;
}

int main(){
    ll N;
    cin >> N;

    Graph G(N);
    for(ll i = 1; i < N; i++) {
        ll num;
        cin >> num;
        G.at(num - 1).push_back(i);
    }

    cout << dfs(G, 0) << endl;

    return 0;
}