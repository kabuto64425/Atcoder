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
    ll Q;
    cin >> Q;
    priority_queue<ll, vector<ll>, greater<ll>> A;
    ll add = 0;
    for(ll i = 0; i < Q; i++) {
        ll query;
        cin >> query;
        if(query == 1) {
            ll X1;
            cin >> X1;
            X1 -= add;
            A.push(X1);
        } else if(query == 2) {
            ll X2;
            cin >> X2;
            add += X2;
        } else {
            cout << A.top() + add << endl;
            A.pop();
        }
    }
    return 0;
}