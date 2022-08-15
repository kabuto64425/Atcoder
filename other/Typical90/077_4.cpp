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

struct Edge {
    int to, cap, rev;
};

class Ford_Fulkerson {
public:
    int size_ = 1;
    bool used[1 << 18];
    vector<Edge> G[1 << 18];

    void init(int sz) {
        size_ = sz;
    }
    void add_edge(int u, int v, int c) {
        G[u].push_back(Edge{ v, c, (int)G[v].size() });
        G[v].push_back(Edge{ u, 0, (int)G[u].size() - 1 });
    }
    int dfs(int pos, int to, int f) {
        if (pos == to) return f;
        used[pos] = true;
        for (int i = 0; i < G[pos].size(); i++) {
            if (used[G[pos][i].to] == true || G[pos][i].cap == 0) continue;
            int z = dfs(G[pos][i].to, to, min(f, G[pos][i].cap));
            if (z != 0) {
                G[pos][i].cap -= z;
                G[G[pos][i].to][G[pos][i].rev].cap += z;
                return z;
            }
        }
        return 0;
    }
    int max_flow(int s, int t) {
        int ret = 0;
        while (true) {
            for (int i = 0; i <= size_; i++) used[i] = false;
            int f = dfs(s, t, 1000000007);
            if (f == 0) break;
            ret += f;
        }
        return ret;
    }
};

const ll dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const ll dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(){
    // Step #1. Input
    ll N, T;
    cin >> N >> T;
    vector<pair<ll, ll>> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i).first >> A.at(i).second;
    }
    vector<pair<ll, ll>> B(N);
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i).first >> B.at(i).second;
    }

    map<pair<ll, ll>, ll> Map;
    for(ll i = 1; i <= N; i++) {
        Map[make_pair(B.at(i - 1).first, B.at(i - 1).second)] = i;
    }

    // Step #2. Add Edge
    Ford_Fulkerson Z;
    Z.init(2 * N + 5);
    vector<vector<ll>> Nex(1 << 18, vector<ll>(8));
    for (ll i = 1; i <= N; i++) {
        for (ll j = 0; j < 8; j++) {
            ll tx = A.at(i - 1).first + dx[j] * T;
            ll ty = A.at(i - 1).second + dy[j] * T;
            Nex[i][j] = Map[make_pair(tx, ty)];
            if (Nex[i][j] != 0) {
                Z.add_edge(i, N + Nex[i][j], 1);
            }
        }
    }
    for (ll i = 1; i <= N; i++) Z.add_edge(2 * N + 1, i, 1);
    for (ll i = 1; i <= N; i++) Z.add_edge(i + N, 2 * N + 2, 1);

    // Step #3. Max Flow
    ll res = Z.max_flow(2 * N + 1, 2 * N + 2);
    if (res != N) {
        cout << "No" << endl;
        return 0;
    }

    // Step #4. Get Answer
    vector<ll> Answer(1 <<18);
    for (ll i = 1; i <= N; i++) {
        for (ll j = 0; j < Z.G[i].size(); j++) {
            if (Z.G[i][j].to > 2 * N || Z.G[i][j].cap == 1) continue;
            for (ll k = 0; k < 8; k++) {
                if (Nex[i][k] == Z.G[i][j].to - N) Answer[i] = k + 1;
            }
        }
    }

    // Step #5. Output
    cout << "Yes" << endl;
    for (ll i = 1; i <= N; i++) {
        if (i >= 2) cout << " ";
        cout << Answer[i];
    }
    cout << endl;
    return 0;
}