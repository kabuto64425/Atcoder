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

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    for(ll i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    Graph G(N);
    for(ll i = 0; i < M; i++) {
        G[A.at(i) - 1].push_back(B.at(i) - 1);
    }
    dsu d(N);
    vector<ll> ans(N);
    ll current = 0;
    for(ll i = N - 1; i >= 0; i--) {
        ans.at(i) = current;
        current++;
        for(ll v :G[i]) {
            if(!d.same(v, i)) {
                current--;
            }
            d.merge(v, i);
        }
    }
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
    return 0;
}