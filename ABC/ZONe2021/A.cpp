#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string S;
    cin >> S;
    ll ans = 0;
    for(ll i = 0; i <= 8; i++) {
        if(S.at(i) == 'Z' and S.at(i + 1) == 'O' and S.at(i + 2) == 'N' and S.at(i + 3) == 'e') {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}