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
    string S;
    cin >> S;
    ll con = 1;
    ll ans = 0;
    for(ll i = S.length() - 1; i >= 2; i--) {
        if(S.at(i) != S.at(i - 1) and S.at(i - 1) == S.at(i - 2)) {
            ans += con;
            con = 1;
        } else {
            con++;
        }
    }
    cout << ans << endl;
    return 0;
}