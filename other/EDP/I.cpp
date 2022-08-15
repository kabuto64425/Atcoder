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
    vector<long double> p(N);
    for(ll i = 0; i < N; i++) {
        cin >> p.at(i);
    }
    vector<vector<long double>> dp(N + 1, vector<long double>(N + 1, 0));
    dp.at(0).at(0) = 1;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            long double pi = p.at(i);
            // 裏
            dp.at(i + 1).at(j) += dp.at(i).at(j) * (1 - pi);
            // 表
            dp.at(i + 1).at(j + 1) += dp.at(i).at(j) * pi;
        }
    }
    long double ans = 0;
    for(ll i = N / 2 + 1; i <= N; i++) {
        ans += dp.at(N).at(i);
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}