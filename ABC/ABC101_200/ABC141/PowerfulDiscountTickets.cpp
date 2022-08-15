#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, M;
    cin >> N >> M;
    priority_queue<ll, vector<ll>, less<ll>> A;

    REP(i, N) {
        ll x;
        cin >> x;
        A.push(x);
    }

    REP(i, M) {
        ll half = A.top() / 2;
        A.pop();
        A.push(half);
    }

    ll ans = 0;
    while(!A.empty()) {
        ans += A.top();
        A.pop();
    }
    cout << ans << endl;
}