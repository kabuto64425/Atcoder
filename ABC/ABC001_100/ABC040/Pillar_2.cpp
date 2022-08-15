#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    vector<ll> dp(N, INF);
    dp.at(0) = 0;
    for(ll i = 0; i < N; i++) {
        if(i < N - 1) {
            dp.at(i + 1) = min(dp.at(i + 1), dp.at(i) + abs(a.at(i + 1) - a.at(i)));
        }
        if(i < N - 2) {
            dp.at(i + 2) = min(dp.at(i + 2), dp.at(i) + abs(a.at(i + 2) - a.at(i)));
        }
    }
    cout << dp.at(N - 1) << endl;
    return 0;
}