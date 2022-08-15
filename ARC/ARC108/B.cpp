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
    ll N;
    cin >> N;
    string s;
    cin >> s;
    stack<ll> a;
    ll state = 0;
    ll ans = N;
    for(ll i = 0; i < N; i++) {
        char c = s.at(i);
        if(c != 'f' && c != 'o' && c != 'x') {
            state = 0;
            a = stack<ll>();
        }
        if(c == 'f') {
            if(state != 0) {
                a.push(state);
                state = 0;
            }
            state++;
        }
        if(c == 'o') {
            if(state == 1) {
                state++;
            } else {
                state = 0;
                a = stack<ll>();
            }
        }
        if(c == 'x') {
            if(state == 2) {
                state++;
            } else {
                state = 0;
                a = stack<ll>();
            }
        }
        if(state == 3) {
            ans -= 3;
            if(!a.empty()) {
                state = a.top();
                a.pop();
            } else {
                state = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}