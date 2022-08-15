#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

signed main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(M);
    REP(i, M) {
        cin >> AB.at(i).first >> AB.at(i).second;
        AB.at(i).first--;
        AB.at(i).second--;
    }
    UnionFind UF(N);
    REP(i, M) {
        UF.merge(AB.at(i).first, AB.at(i).second);
    }
    ll ans = 0;
    REP(i, N) {
        ans = max(ans, (ll)UF.size(i));
    }
    cout << ans << endl;
}