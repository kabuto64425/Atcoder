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

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<mint> C1(K);
    C1.at(0) = 1;
    for(ll i = 1; i <= K - 1; i++) {
        C1.at(i) = C1.at(i - 1) * (K - i) / i;
    }
    vector<mint> C2(K + 1);
    C2.at(0) = 1;
    for(ll i = 1; i <= min(N - K + 1, K); i++) {
        C2.at(i) = C2.at(i - 1) * (N - K + 2 - i) / i;
    }
    for(ll i = 1; i <= K; i++) {
        cout << (C1.at(i - 1) * C2.at(i)).val() << endl;
    }
    return 0;
}