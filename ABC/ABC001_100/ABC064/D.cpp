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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    while(true) {
        ll x = 0;
        ll state = 0;
        for(ll i = 0; i < (ll)S.length(); i++) {
            char c = S.at(i);
            if(c == '(') {
                x++;
            }
            if(c == ')') {
                x--;
            }
            if(x < 0) {
                state = 1;
                break;
            }
        }
        if(state == 0 and x != 0) {
            state = 2;
        }
        if(state == 0) {
            break;
        } else if(state == 1) {
            S = '(' + S;
        } else if(state == 2) {
            S =  S + ')';
        }
    }
    cout << S << endl;
    return 0;
}