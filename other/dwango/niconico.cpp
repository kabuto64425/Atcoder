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
    ll ans = 0;
    bool flag = false;
    ll current = 0;
    for(ll i = 0; i < S.length(); i++) {
        char c = S.at(i);
        if(c == '2') {
            if(!flag) {
                flag = true;
            } else {
                ans += current * (current + 1) / 2;
                current = 0;
            }
        } else if(c == '5') {
            if(flag) {
                flag = false;
                current++;
            } else {
                ans += current * (current + 1) / 2;
                current = 0;
            }
        } else {
            flag = false;
            ans += current * (current + 1) / 2;
            current = 0;
        }
    }
    ans += current * (current + 1) / 2;
    cout << ans << endl;
    return 0;
}