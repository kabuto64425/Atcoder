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
    string S;
    cin >> S;
    ll T;
    cin >> T;
    ll x = 0;
    ll y = 0;
    ll question = 0;
    for(const char &c : S) {
        if(c == 'R') {
            x++;
        }
        if(c == 'L') {
            x--;
        }
        if(c == 'U') {
            y++;
        }
        if(c == 'D') {
            y--;
        }
        if(c == '?') {
            question++;
        }
    }
    if(T == 1) {
        cout << abs(x) + abs(y) + question << endl;
    } else {
        if(question > abs(x) + abs(y)) {
            cout << (question - (abs(x) + abs(y))) % 2 << endl;
        } else {
            cout << abs(x) + abs(y) - question << endl;
        }
    }
    return 0;
}