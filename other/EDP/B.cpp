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
    ll N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for(ll i = 0; i < N; i++) {
        cin >> h.at(i);
    }
    vector<ll> dp(N, INF);
    dp.at(0) = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 1; j <= K; j++) {
            if(i + j < N) {
                dp.at(i + j) = min(dp.at(i + j), dp.at(i) + abs(h.at(i + j) - h.at(i)));
            }
        }
    }
    cout << dp.at(N - 1) << endl;
    return 0;
}