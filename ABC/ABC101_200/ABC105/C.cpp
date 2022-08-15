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
    ll N;
    cin >> N;
    if(N == 0) {
        cout << 0 << endl;
        return 0;
    }
    stack<ll> ans;
    ll dig = 0;
    while(N != 0) {
        ll mod = (N % 2 + 2) % 2;
        N = -((N - mod) / 2);
        ans.push(mod);
    }
    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
    return 0;
}