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
    
    vector<ll> ans(N, 1);
    for(ll i = 0; i < Q; i++) {
        cout << ans.at(x.at(i)) << endl;
        ans.at(x.at(i)) = y.at(i);
        for(ll nv : G[x.at(i)]) {
            ans.at(nv) = y.at(i);
        }
    }
    return 0;
}