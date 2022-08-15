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
    ll A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<long double>>> dp(110, vector<vector<long double>>(110, vector<long double>(110, 0.0)));
    for(ll a = 100; a >= 0; a--) {
        for(ll b = 100; b >= 0; b--) {
            for(ll c = 100; c >= 0; c--) {
                if(a == 100 or b == 100 or c == 100) {
                    dp[a][b][c] = 0;
                    continue;
                }
                dp[a][b][c] += (dp[a + 1][b][c] + 1) * a / (long double)(a + b + c);
                dp[a][b][c] += (dp[a][b + 1][c] + 1) * b / (long double)(a + b + c);
                dp[a][b][c] += (dp[a][b][c + 1] + 1) * c / (long double)(a + b + c);
            }
        }
    }
    cout << fixed << setprecision(20) << dp[A][B][C] << endl;
    return 0;
}