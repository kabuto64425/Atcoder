#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string s;
    cin >> s;
    ll ans = 0;
    ll current = 0;
    char previous = ' ';
    for(const char &c : s) {
        if(c == '2') {
            if(previous != '5') {
                ans += current * (current + 1) / 2;
                current = 0;
            }
        } else if(c == '5') {
            if(previous == '2') {
                current++;
            } else {
                ans += current * (current + 1) / 2;
                current = 0;
            }
        } else {
            ans += current * (current + 1) / 2;
            current = 0;
        }
        previous = c;
    }
    ans += current * (current + 1) / 2;
    cout << ans << endl;
    return 0;
}