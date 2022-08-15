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

void findParent(const Graph &G, vector<ll> &parent, ll v = 0, ll pre = -1, ll d = 0) {
    parent.at(v) = pre;
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        findParent(G, parent, nv, v, d + 1);
    }
}

void dfs(const Graph &G, vector<ll> &ans, ll v = 0, ll pre = -1) {
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        ans.at(nv) += ans.at(v);
        dfs(G, ans, nv, v);
    }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N - 1), b(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    ll Q;
    cin >> Q;
    vector<ll> t(Q), e(Q), x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> t.at(i) >> e.at(i) >> x.at(i);
        e.at(i)--;
    }

    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G[a.at(i)].push_back(b.at(i));
        G[b.at(i)].push_back(a.at(i));
    }

    vector<ll> parent(N, -1);
    findParent(G, parent);

    vector<ll> ans(N);
    for(ll i = 0 ; i < Q; i++) {
        ll v1 = a.at(e.at(i));
        ll v2 = b.at(e.at(i));
        if(t.at(i) == 2) {
            swap(v1, v2);
        }
        // v1:通る
        // v2:通らない
        if(parent.at(v1) == v2) {
            ans.at(v1) += x.at(i);
        } else {
            ans.at(0) += x.at(i);
            ans.at(v2) -= x.at(i);
        }
    }
    dfs(G, ans);
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
    return 0;
}