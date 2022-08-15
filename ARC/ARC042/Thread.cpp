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
    ll N, M;
    cin >> N >> M;
    stack<ll> a;
    REP(i, M) {
        ll x;
        cin >> x;
        a.push(x);
    }
    vector<bool> flags(N + 1, false);
    while(!a.empty()) {
        ll x = a.top();
        a.pop();
        if(!flags.at(x)) {
            cout << x << endl;
            flags.at(x) = true;
        }
    }

    for(ll i = 1; i <= N; i++) {
        if(!flags.at(i)) {
            cout << i << endl;
        }
    }
    return 0;
}