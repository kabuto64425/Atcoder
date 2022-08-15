#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    for(ll &a : A) {
        cin >> a;
    }
    for(ll &b : B) {
        cin >> b;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, INF));
    dp[0][0] = 0;
    for(ll i = 0; i <= N; i++) {
        for(ll j = 0; j <= M; j++) {
            if(i > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if(j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if(i > 0 and j > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + ((A[i - 1] == B[j - 1])? 0 : 1));
            }
        }
    }
    cout << dp[N][M] << endl;
}