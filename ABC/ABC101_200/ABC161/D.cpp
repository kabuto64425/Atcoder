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
    ll K;
    cin >> K;
    queue<ll> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    ll ans = 0;

    for(ll i = 0; i < K; i++) {
        ans = q.front();
        q.pop();
        ll x = ans;
        if(x % 10 != 0) {
            q.push(x * 10 + x % 10 - 1);
        }
        q.push(x * 10 + x % 10);
        if(x % 10 != 9) {
            q.push(x * 10 + x % 10 + 1);
        }
    }
    cout << ans << endl;
    return 0;
}