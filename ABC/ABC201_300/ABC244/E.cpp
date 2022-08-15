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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

int main(){
    ll N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    vector<ll> U(M) , V(M);
    for(ll i = 0; i < M; i++) {
        cin >> U.at(i) >> V.at(i);
    }
    Graph G(N + 1);
    for(ll i = 0; i < M; i++) {
        G[U.at(i)].push_back(V.at(i));
        G[V.at(i)].push_back(U.at(i));
    }
    vector<vector<vector<mint>>> dp(K + 1, vector<vector<mint>>(N + 1, vector<mint>(2)));
    dp.at(0).at(S).at(0) = 1;
    for(ll i = 0; i < K; i++) {
        for(ll j = 1; j <= N; j++) {
            for(ll next : G[j]) {
                if(next == X) {
                    dp.at(i + 1).at(next).at(0) += dp.at(i).at(j).at(1);
                    dp.at(i + 1).at(next).at(1) += dp.at(i).at(j).at(0);
                } else {
                    dp.at(i + 1).at(next).at(0) += dp.at(i).at(j).at(0);
                    dp.at(i + 1).at(next).at(1) += dp.at(i).at(j).at(1);
                }
            }
        }
    }
    cout << dp.at(K).at(T).at(0).val() << endl;
    return 0;
}