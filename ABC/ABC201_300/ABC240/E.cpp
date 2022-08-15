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

void dfs(Graph &G, vector<pair<ll, ll>> &ans, ll& count, ll v, ll pre) {
    ans.at(v).first = count;
    bool flag = true;
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        flag = false;
        dfs(G, ans, count, nv, v);
    }
    if(flag) {
        count++;
    }
    ans.at(v).second = count - 1;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> u(N), v(N);
    for(ll i = 0; i < N - 1; i++) {
        cin >> u.at(i) >> v.at(i);
        u.at(i)--;
        v.at(i)--;
    }
    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G[u.at(i)].push_back(v.at(i));
        G[v.at(i)].push_back(u.at(i));
    }
    vector<pair<ll, ll>> ans(N);
    ll count = 1;
    dfs(G, ans, count, 0, -1);
    for(ll i = 0; i < N;i++) {
        cout << ans.at(i).first << " " << ans.at(i).second << endl;
    }
    return 0;
}