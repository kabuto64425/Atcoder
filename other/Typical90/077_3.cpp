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

using Graph = vector<vector<pair<ll, ll>>>;

const vector<pair<ll, ll>> uv = {
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, -1}
};

void dfs(const ll N, const Graph &G, ll v, vector<bool> &seen, ll &countA, ll &countB) {
    if(v < N) {
        countA++;
    } else {
        countB++;
    }
    
    seen[v] = true;
    
    for(pair<ll, ll> nv : G[v]) {
        if(seen[nv.first]) {
            continue;
        }
        dfs(N, G, nv.first, seen, countA, countB);
    }
}

void dfs2(const ll N, const Graph &G, ll v, ll pre, vector<ll> &ans) {
    for(pair<ll, ll> nv : G[v]) {
        if(nv.first == pre) {
            continue;
        }
        if(v < N) {
            ans.at(v) = nv.second;
        }

        dfs2(N, G, nv.first, v, ans);
    }
}

int main(){
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

    Graph G(2 * N);
    map<ll, ll> mb;
    for(ll i = 0; i < N; i++) {
        mb[B.at(i).first] = N + i;
    }

    for(ll i = 0; i < N; i++) {
        if(mb.count(A.at(i).first + T)) {
            ll b = mb[A.at(i).first + T];
            G[i].push_back({b, 1});
            G[b].push_back({i, 1});
        }
        if(mb.count(A.at(i).first - T)) {
            ll b = mb[A.at(i).first - T];
            G[i].push_back({b, 5});
            G[b].push_back({i, 5});
        }
    }

    vector<bool> seen(2 * N, false);

    for(ll i = 0; i < N; i++) {
        if(seen[i]) {
            continue;
        }
        ll countA = 0;
        ll countB = 0;
        dfs(N, G, i, seen, countA, countB);
        if(countA != countB) {
            cout << "No" << endl;
            return 0;
        }
    }

    vector<ll> ans(N);

    for(ll i = 0; i < N; i++) {
        if(G[i].size() != 1) {
            continue;
        }
        dfs2(N, G, i, -1, ans);
    }

    cout << "Yes" << endl;
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;

    return 0;
}