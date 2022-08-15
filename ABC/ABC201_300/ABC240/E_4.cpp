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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

void dfs(Graph &G, ll v, ll pre, vector<pair<ll, ll>> &ans, ll &x) { 
    ans.at(v).first = x;
    bool saw = false;
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        dfs(G, nv, v, ans, x);
        saw = true;
    }
    if(!saw) {
        x++;
    }
    ans.at(v).second = x - 1;
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
    ll x = 1;
    dfs(G, 0, -1, ans, x);
    for(ll i = 0; i < N; i++) { 
        cout << ans.at(i).first << " " << ans.at(i).second << endl;
    }
    return 0;
}