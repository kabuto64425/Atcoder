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

void dfs(Graph &G, ll v, ll pre, const vector<ll> &X, vector<vector<ll>> &info, vector<ll> &V, vector<ll> &K) {
    vector<ll> &vec = info.at(v);
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        dfs(G, nv, v, X, info, V, K);
        vec.insert(vec.end(), ALL(info.at(nv)));
    }
    vec.push_back(X.at(v));
    sort(ALL(vec), greater<ll>());
    if(vec.size() > 20) {
        vec.erase(vec.begin() + 21, vec.end());
    }
}

int main(){
    priority_queue<ll, vector<ll>, less<ll>> pq;
    pq.push(2);
    pq.push(1);
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
    vector<vector<ll>> info(N);
    dfs(G, 0, -1, X, info, V, K);
    for(ll i = 0; i < Q; i++) {
        cout << info.at(V.at(i) - 1).at(K.at(i) - 1) << endl;
    }
    return 0;
}