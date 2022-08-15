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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll a = 0;
    for(ll i = 1; i < N; i++) {
        if(S.at(i) != S.at(i - 1)) {
            a++;
        }
    }
    cout << N - 1 - max(a - 2 * K, 0LL) << endl;
    return 0;
}