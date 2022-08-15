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
    vector<ll> X(N), Y(N), Z(N);
    for(ll i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i) >> Z.at(i);
    }
    vector<vector<ll>> dp((1 << 20), vector<ll>(20, INF));
    dp.at(0).at(0) = 0;
    for(ll bit = 0; bit < (1 << N); bit++) {
        for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
            // i:前回
            // j:今回
            chmin(dp.at(bit | (1 << j)).at(j), dp.at(bit).at(i) + abs(X.at(i) - X.at(j)) + abs(Y.at(i) - Y.at(j)) + max(0LL, Z.at(j) - Z.at(i)));
        }
    }
    cout << dp.at((1 << N) - 1).at(0) << endl;
    return 0;
}