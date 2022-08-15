#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; i ++) {
        cin >> X.at(i) >> Y.at(i);
    }

    vector<vector<ll>> d(N, vector<ll>(N));
    for(ll i = 0; i < N; i ++) {
        for(ll j = 0; j < N; j++) {
            d.at(i).at(j) = (X.at(i) - X.at(j)) * (X.at(i) - X.at(j)) + (Y.at(i) - Y.at(j)) * (Y.at(i) - Y.at(j));
        }
    }

    vector<ll> cost(1 << N);
    // bit: どの点を含むかという集合を2進数で表した
    // cost: 添字を2進数で表された点の集合としたとき、集合に含まれる点の中で、最も離れている点同士の距離
    for (ll bit = 1; bit < (1 << N); bit++) {
        for (ll j = 0; j < N; j++) {
            for (ll k = 0; k < j; k++) {
                // j と k がともに集合に含まれている条件
                if ((bit & (1 << j)) and (bit & (1 << k))) {
                    cost[bit] = max(cost[bit], d[j][k]);
                }
            }
        }
    }
    vector<vector<ll>> dp(K + 1, vector<ll>(1 << N, 1LL << 62));
    dp.at(0).at(0) = 0;
    for (ll i = 1; i <= K; i++) {
        for (ll bit = 1; bit < (1 << N); bit++) {
            // k: 今回選ぼうとしている点の集合
            // bit - k: 前回までで選ばれていた点の集合
            // bit: 今回も含め、選ばれている点の集合
            for (ll k = bit; k != 0; k = (k - 1) & bit) {
                dp[i][bit] = min(dp[i][bit], max(dp[i - 1][bit - k], cost[k]));
            }
        }
    }
    cout << dp.at(K).at((1 << N) - 1) << endl;
    return 0;
}