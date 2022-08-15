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

void dfs(const Graph &G, const vector<ll> &X, ll v, ll pre, vector<vector<ll>> &vec) {
    for(ll next_v : G[v]) {
        if(next_v == pre) {
            continue;
        }
        dfs(G, X, next_v, v, vec);
        for(ll elm : vec.at(next_v)) {
            vec.at(v).push_back(elm);
        }
    }
    vec.at(v).push_back(X.at(v));
    sort(ALL(vec.at(v)), greater<ll>());
    if(vec.at(v).size() > 20) {
        vec.at(v).erase(vec.at(v).begin() + 20, vec.at(v).end());
    }
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N);
    for(ll i = 0; i < N; i++) {
        cin >> X.at(i);
    }
    vector<ll> A(N - 1), B(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<ll> V(Q), K(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> V.at(i) >> K.at(i);
    }
    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G[A.at(i) - 1].push_back(B.at(i) - 1);
        G[B.at(i) - 1].push_back(A.at(i) - 1);
    }
    vector<vector<ll>> vec(N);
    dfs(G, X, 0, -1, vec);
    for(ll i = 0; i < Q; i++) {
        cout << vec.at(V.at(i) - 1).at(K.at(i) - 1) << endl;
    }
    return 0;
}