#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
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
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    vector<vector<mint>> dp(N + 1, vector<mint>(110000));
    dp.at(0).at(0) = 1;
    vector<vector<mint>> sum(N + 1, vector<mint>(110000));
    sum.at(0).at(0) = dp.at(0).at(0);
    for(ll i = 1; i <= 100000; i++) {
        sum.at(0).at(i) = sum.at(0).at(i - 1) + dp.at(0).at(i);
    }
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 100000; j++) {
            if(j - a.at(i - 1) - 1 < 0) {
                dp.at(i).at(j) += sum.at(i - 1).at(j);
            } else {
                dp.at(i).at(j) += sum.at(i - 1).at(j) - sum.at(i - 1).at(j - a.at(i - 1) - 1);
            }
        }
        sum.at(i).at(0) = dp.at(i).at(0);
        for(ll j = 1; j <= 100000; j++) {
            sum.at(i).at(j) = sum.at(i).at(j - 1) + dp.at(i).at(j);
        }
    }
    cout << dp.at(N).at(K).val() << endl;
    return 0;
}