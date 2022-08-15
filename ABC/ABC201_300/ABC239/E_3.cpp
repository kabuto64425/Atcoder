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

void dfs(Graph &G, ll v, ll pre, vector<vector<ll>> &vec1, const vector<ll> &X) {
    vec1.at(v).push_back(X.at(v));
    for(ll nv : G[v]) {
        if(nv == pre) {
            continue;
        }
        dfs(G, nv, v, vec1, X);
    }

    sort(ALL(vec1.at(v)), greater<ll>());
    if(vec1.at(v).size() > 20) {
        vec1.at(v).erase(vec1.at(v).begin() + 20, vec1.at(v).end());
    }

    if(pre == -1) {
        return;
    }
    
    for(ll i = 0; i < vec1.at(v).size(); i++) {
        vec1.at(pre).push_back(vec1.at(v).at(i));
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
    
    vector<vector<ll>> vec1(N);
    dfs(G, 0, -1, vec1, X);

    for(ll i = 0; i < Q; i++) {
        cout << vec1.at(V.at(i) - 1).at(K.at(i) - 1) << endl;
    }
    
    return 0;
}