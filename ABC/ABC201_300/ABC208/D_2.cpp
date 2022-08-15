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

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M), C(M);
    for(ll i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i) >> C.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(N + 1, INF)));
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    for(ll i = 0; i < M; i++) {
        dist[A.at(i)][B.at(i)] = C.at(i);
        dp[A.at(i)][B.at(i)][0] = C.at(i);
    }
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
        dp[i][i][0] = 0;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dp[i][j][k + 1] = min(dp[i][j][k],  dp[i][k][k] + dp[k][j][k]);
            }
            dp[i][i][k + 1] = 0;
        }
    }
    ll ans = 0;
    for (int k = 1; k <= N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(dp[i][j][k] != INF) {
                    ans += dp[i][j][k];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}