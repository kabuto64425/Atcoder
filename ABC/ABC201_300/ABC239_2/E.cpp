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

void dfs(ll v, ll pre, const Graph &G, const vector<ll> &X, vector<vector<ll>> &ans) {
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        dfs(nv, v, G, X, ans);
        for(ll elm : ans.at(nv)) {
            ans.at(v).push_back(elm);
        }
    }
    ans.at(v).push_back(X.at(v));
    sort(ALL(ans.at(v)), greater<ll>());
    if(ans.at(v).size() > 30) {
        ans.at(v).erase(ans.at(v).begin() + 30, ans.at(v).end());
    }
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N);
    for(ll &x : X) {
        cin >> x;
    }
    vector<ll> A(N - 1), B(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    vector<ll> V(Q), K(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> V.at(i) >> K.at(i);
    }

    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G[A.at(i)].push_back(B.at(i));
        G[B.at(i)].push_back(A.at(i));
    }

    vector<vector<ll>> ans(N);
    dfs(0, -1, G, X, ans);
    for(ll i = 0; i < Q; i++) {
        cout << ans.at(V.at(i) - 1).at(K.at(i) - 1) << endl;
    }
    return 0;
}