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
    ll H, W, K, V;
    cin >> H >> W >> K >> V;
    vector<vector<ll>> sum(H + 1, vector<ll>(W + 1, 0));
    for(ll i = 1; i <= H; i ++) {
        for(ll j = 1; j <= W; j++) {
            ll A;
            cin >> A;
            sum[i][j] += (A + K);
        }
    }
    for(ll i = 1; i <= H; i++) {
        for(ll j = 1; j <= W; j++) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    for(ll j = 1; j <= W; j++) {
        for(ll i = 1; i<= H; i++) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    ll ans = 0;
    for(ll i1 = 0; i1 <= H; i1++) {
        for(ll j1 = 0; j1 <= W; j1++) {
            for(ll i2 = i1; i2 <= H; i2++) {
                for(ll j2 = j1; j2 <= W; j2++) {
                    if(sum[i2][j2] - sum[i1][j2] - sum[i2][j1] + sum[i1][j1] <= V) {
                        ans = max(ans, (i2 - i1) * (j2 - j1));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}