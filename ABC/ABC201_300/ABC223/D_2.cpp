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

bool topo_sort(ll N, const Graph &G, vector<ll> &ans) {
    vector<ll> ind(N);
    for(ll i = 0; i < N; i ++) {
        for(ll e : G.at(i)) {
            ind.at(e)++;
        }
    }
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for(ll i = 0; i < N; i++) {
        if(ind.at(i) == 0) {
            que.push(i);
        }
    }
    while(!que.empty()) {
        ll now = que.top();
        ans.push_back(now);
        que.pop();
        for(ll e : G.at(now)) {
            ind.at(e)--;
            if(ind.at(e) == 0) {
                que.push(e);
            }
        }
    }
    if((ll)ans.size() != N) {
        return false;
    }
    return true;
}

int main(void) {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    for(ll i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    Graph G(N);
    for(ll i = 0; i < M; i++) {
        G[A.at(i)].push_back(B.at(i));
    }
    vector<ll> ans;
    if(!topo_sort(N, G, ans)) {
        cout << -1 << endl;
        return 0;
    }
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) + 1 << " ";
    }
    cout << endl;
}