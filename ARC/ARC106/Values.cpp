#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
    }
 
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }
 
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }
 
    int size(int x) {
        return -r[root(x)];
    }
};

signed main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    vector<ll> b(N);
    REP(i, N) {
        cin >> a.at(i);
    }
    REP(i, N) {
        cin >> b.at(i);
    }
    vector<pair<ll, ll>> cd(M);
    REP(i, M) {
        cin >> cd.at(i).first >> cd.at(i).second;
    }

    UnionFind UF(N);

    for (int i = 0; i < M; i++)
    {
        cd.at(i).first -= 1;
        cd.at(i).second -= 1;
        UF.unite(cd.at(i).first, cd.at(i).second);
    }

    vector<ll> sumsA(N, 0);
    vector<ll> sumsB(N, 0);
    REP(i, N) {
        sumsA.at(UF.root(i)) += a.at(i);
        sumsB.at(UF.root(i)) += b.at(i);
    }

    REP(i, N) {
        if(sumsA.at(UF.root(i)) != sumsB.at(UF.root(i))) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}