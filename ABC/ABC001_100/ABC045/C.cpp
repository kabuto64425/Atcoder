#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string S;
    cin >> S;
    ll N = S.length() - 1;
    ll ans = 0;
    for(ll bit = 0; bit < (1 << N); bit++) {
        ll current = S.at(0) - '0';
        for(ll i = 0; i < N ; i++) {
            if(bit & (1 << i)) {
                ans += current;
                current = S.at(i + 1) - '0';
            } else {
                current *= 10;
                current += S.at(i + 1) - '0';
            }
        }
        ans += current;
    }
    cout << ans << endl;
    return 0;
}