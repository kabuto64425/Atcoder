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
    ll K;
    cin >> K;
    string A, B;
    cin >> A >> B;

    ll C = 0;
    ll k = 1;
    for(ll i = A.length() - 1; i >= 0; i--) {
        C += ((ll)(A.at(i) - '0')) * k;
        k *= K;
    }

    ll D = 0;
    k = 1;
    for(ll i = B.length() - 1; i >= 0; i--) {
        D += ((ll)(B.at(i) - '0')) * k;
        k *= K;
    }

    cout << C * D << endl;
    
    return 0;
}