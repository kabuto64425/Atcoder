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
    ll H, N;
    cin >> H >> N;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<ll> dp(11000, INF);
    dp.at(0) = 0;
    for(ll i = 0; i <= H; i++) {
        for(ll j = 0; j < N; j++) {
            ll d = A.at(j);
            if(i - d >= 0) {
                dp.at(i) = min(dp.at(i), dp.at(i - d) + B.at(j));
            } else {
                dp.at(i) = min(dp.at(i), dp.at(0) + B.at(j));
            }
        }
    }
    cout << dp.at(H) << endl;
    return 0;
}