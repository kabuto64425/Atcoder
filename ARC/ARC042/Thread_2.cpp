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
    ll N, M;
    cin >> N >> M;
    vector<bool> read(N, false);
    stack<ll> s;
    for(ll i = 1; i <= N; i++) {
        s.push(N + 1 - i);
    }
    REP(i, M) {
        ll a;
        cin >> a;
        s.push(a);
    }
    while(!s.empty()) {
        ll a = s.top();
        s.pop();
        if(!read.at(a - 1)) {
            cout << a << endl;
            read.at(a - 1) = true;
        }
    }
    return 0;
}