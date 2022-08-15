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

void dfs(const Graph &G, ll v, ll pre, ll &x, vector<pair<ll, ll>> &ans) {
    ans.at(v).first = x;
    bool flag = true;
    for(ll next_v: G[v]) {
        if(next_v == pre) {
            continue;
        }
        flag = false;
        dfs(G, next_v, v, x, ans);
    }
    if(flag) {
        x++;
    }
    ans.at(v).second = x - 1;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> u(N - 1), v(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> u.at(i) >> v.at(i);
    }
    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G[u.at(i) - 1].push_back(v.at(i) - 1);
        G[v.at(i) - 1].push_back(u.at(i) - 1);
    }
    vector<pair<ll, ll>> ans(N);
    ll x = 1;
    dfs(G, 0, -1, x, ans);
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i).first << " " << ans.at(i).second << endl;
    }
    return 0;
}