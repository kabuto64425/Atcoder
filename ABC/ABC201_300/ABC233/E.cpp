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
    ll L = X.length();
    vector<ll> csum(L + 1);
    for(ll i = 1; i <= L; i++) {
        csum.at(i) = csum.at(i - 1) + ((ll)(X.at(i - 1) - '0'));
    }
    ll upper = 0;
    stack<ll> stack;
    for(ll i = L; i >= 1; i--) {
        ll r = upper + csum.at(i);
        ll s = r % 10;
        upper = r / 10;
        stack.push(s);
    }
    if(upper > 0) {
        cout << upper;
    }
    while(!stack.empty()) {
        cout << stack.top();
        stack.pop();
    }
    cout << endl;
    return 0;
}