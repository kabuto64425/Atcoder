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
    ll N;
    cin >> N;
    vector<ll> h(N + 1);
    for(ll i = 1; i <= N; i++) {
        cin >> h.at(i);
    }
    vector<ll> dp(N + 1, INF);
    dp.at(0) = 0;
    dp.at(1) = 0;
    for(ll i = 1; i <= N; i++) {
        if(i + 1 <= N) {
            chmin(dp.at(i + 1), dp.at(i) + abs(h.at(i + 1) - h.at(i)));
        }
        if(i + 2 <= N) {
            chmin(dp.at(i + 2), dp.at(i) + abs(h.at(i + 2) - h.at(i)));
        }
    }
    cout << dp.at(N) << endl;
    return 0;
}