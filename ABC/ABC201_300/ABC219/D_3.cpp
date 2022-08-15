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

int main(){
    ll N;
    cin >> N;
    ll X, Y;
    cin >> X >> Y;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<vector<vector<ll>>> dp(301, vector<vector<ll>>(301, vector<ll>(301, INF)));
    for(ll i = 0; i <= N; i++) {
        dp.at(i).at(0).at(0) = 0;
    }
    for(ll i = 1; i <= N; i++) {
        ll a = A.at(i - 1);
        ll b = B.at(i - 1);
        for(ll x = 0; x <= 300; x++) {
            for(ll y = 0; y <= 300; y++) {
                dp.at(i).at(x).at(y) = min(dp.at(i - 1).at(x).at(y), dp.at(i - 1).at(max(x - a, 0LL)).at(max(y - b, 0LL)) + 1);
            }
        }
    }
    ll ans = INF;
    for(ll x = X; x <= 300; x++) {
        for(ll y = Y; y <= 300; y++) {
            ans = min(ans, dp.at(N).at(x).at(y));
        }
    }
    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}