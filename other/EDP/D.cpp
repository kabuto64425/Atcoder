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
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    for(ll i = 0; i < N; i++) {
        cin >> w.at(i) >> v.at(i);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(110000, 0));
    dp.at(0).at(0) = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j <= 100000; j++) {
            chmax(dp.at(i + 1).at(j), dp.at(i).at(j));
            if(j + w.at(i) <= 100000) {
                chmax(dp.at(i + 1).at(j + w.at(i)), dp.at(i).at(j) + v.at(i));
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i <= W; i++) {
        chmax(ans, dp.at(N).at(i));
    }
    cout << ans << endl;
    return 0;
}