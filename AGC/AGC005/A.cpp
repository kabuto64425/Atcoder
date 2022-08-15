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
    string X;
    cin >> X;
    ll N = X.length();
    stack<char> s;
    for(char c : X) {
        if(s.empty()) {
            s.push(c);
        } else {
            char l = s.top();
            if(l == 'S' and c == 'T') {
                s.pop();
            } else {
                s.push(c);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}