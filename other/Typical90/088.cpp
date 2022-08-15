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

void dfs(const Graph &G, const ll N, const vector<ll> &A, vector<ll> &c, vector<ll> &vec, vector<vector<vector<ll>>> &ans, bool &flag, ll pos, ll dep) {
    if(flag) {
        return;
    }
    if(pos == N) {
        ans.at(dep).push_back(vec);
        if(ans.at(dep).size() >= 2) {
            flag = true;
        }
        return;
    }
    
    // 選ばない
    dfs(G, N, A, c, vec, ans, flag, pos + 1, dep);

    // 選ぶ
    if (c.at(pos) == 0) {
        vec.push_back(pos);
        for (ll i : G[pos]) c.at(i)++;
        dfs(G, N, A, c, vec, ans, flag, pos + 1, dep + A.at(pos));
        for (int i : G[pos]) c.at(i)--;
        vec.pop_back();
    }
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> X(Q), Y(Q);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < Q; i++) {
        cin >> X.at(i) >> Y.at(i);
        X.at(i)--;
        Y.at(i)--;
    }
    Graph G(N);
    
    for(ll i = 0; i < Q; i++) {
        G[X.at(i)].push_back(Y.at(i));
        G[Y.at(i)].push_back(X.at(i));
    }

    vector<ll> c(N, 0);
    vector<ll> vec;
    vector<vector<vector<ll>>> ans(10000);
    bool flag = false;
    dfs(G, N, A, c, vec, ans, flag, 0, 0);
    for(ll dep = 0; dep <= 8890; dep++) {
        if(ans.at(dep).size() >= 2) {
            cout << ans.at(dep).at(0).size() << endl;
            for(ll i = 0; i < ans.at(dep).at(0).size(); i++) {
                cout << ans.at(dep).at(0).at(i) + 1 << " ";
            }
            cout << endl;
            cout << ans.at(dep).at(1).size() << endl;
            for(ll i = 0; i < ans.at(dep).at(1).size(); i++) {
                cout << ans.at(dep).at(1).at(i) + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}