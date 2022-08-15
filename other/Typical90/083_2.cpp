#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    for(ll i = 0; i < M; i++) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    ll Q;
    cin >> Q;
    vector<ll> x(Q), y(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i) >> y.at(i);
        x.at(i)--;
    }
    Graph G(N);
    for(ll i = 0; i < M; i++) {
        G[a.at(i)].push_back(b.at(i));
        G[b.at(i)].push_back(a.at(i));
    }

    ll B = ll(sqrtl(2 * M));
    vector<ll> large;
    for (ll i = 0; i < N; ++i) {
        if (G.at(i).size() >= B) {
            large.push_back(i);
        }
    }
    vector<vector<bool> > link(N, vector<bool>(large.size(), false));
    for (ll i = 0; i < large.size(); ++i) {
        for (ll j : G[large[i]]) {
            link[j][i] = true;
        }
        link[large[i]][i] = true;
    }
    vector<ll> update(N, -1);
    vector<ll> update_large(large.size(), -1);
    for (ll i = 0; i < Q; ++i) {
        ll last = update[x[i]];
        for (ll j = 0; j < large.size(); ++j) {
            if (link[x[i]][j]) {
                last = max(last, update_large[j]);
            }
        }
        cout << (last != -1 ? y[last] : 1) << endl;
        if (G[x[i]].size() < B) {
            update[x[i]] = i;
            for (ll j : G[x[i]]) {
                update[j] = i;
            }
        }
        else {
            ll ptr = find(large.begin(), large.end(), x[i]) - large.begin();
            update_large[ptr] = i;
        }
    }
    return 0;
}