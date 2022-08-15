#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> U(M), V(M);
    for(ll i = 0; i < M; i++) {
        cin >> U.at(i) >> V.at(i);
        U.at(i)--;
        V.at(i)--;
    }
    Graph G(N);
    for(ll i = 0; i < M; i++) {
        G[U.at(i)].push_back(V.at(i));
        G[V.at(i)].push_back(U.at(i));
    }
    vector<vector<mint>> dp(K + 1, vector<mint>(N, 0));
    dp.at(0).at(0) = 1;
    vector<mint> sum(K + 1);
    sum.at(0) += dp.at(0).at(0);
    for(ll i = 0; i < K; i++) {
        for(ll j = 0; j < N; j++) {
            dp.at(i + 1).at(j) = sum.at(i);
            dp.at(i + 1).at(j) -= dp.at(i).at(j);
            for(ll nv : G[j]) {
                dp.at(i + 1).at(j) -= dp.at(i).at(nv);
            }
        }
        for(ll j = 0; j < N; j++) {
            sum.at(i + 1) += dp.at(i + 1).at(j);
        }
    }
    cout << dp.at(K).at(0).val() << endl;
    return 0;
}