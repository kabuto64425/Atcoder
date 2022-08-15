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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

using Graph = vector<vector<ll>>;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<pair<ll, ll>> UV(M);
    for(pair<ll, ll> &uv : UV) {
        cin >> uv.first >> uv.second;
        uv.first--;
        uv.second--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[UV[i].first].push_back(UV[i].second);
        G[UV[i].second].push_back(UV[i].first);
    }

    vector<vector<mint>> dp(K + 1, vector<mint>(N, 0));
    dp.at(0).at(0) = 1;
    vector<mint> csum(K + 1, 0);
    csum.at(0) = dp.at(0).at(0);
    for(ll i = 1; i <= K; i++) {
        for(ll j = 0; j < N; j++) {
            dp.at(i).at(j) = csum.at(i - 1);
            dp.at(i).at(j) -= dp.at(i - 1).at(j);
            for (ll nv : G[j]) {
                dp.at(i).at(j) -= dp.at(i - 1).at(nv);
            }
            csum.at(i) += dp.at(i).at(j);
        }
    }
    cout << dp.at(K).at(0).val() << endl;
    return 0;
}