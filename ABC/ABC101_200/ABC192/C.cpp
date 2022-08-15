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

ll g1(ll N) {
    priority_queue<ll, vector<ll>, less<ll>> pq;
    ll x = N;
    while(x > 0) {
        pq.push(x % 10);
        x /= 10;
    }
    ll res = 0;
    while(!pq.empty()) {
        res *= 10;
        res += pq.top();
        pq.pop();
    }
    return res;
}

ll g2(ll N) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll x = N;
    while(x > 0) {
        pq.push(x % 10);
        x /= 10;
    }
    ll res = 0;
    while(!pq.empty()) {
        res *= 10;
        res += pq.top();
        pq.pop();
    }
    return res;
}

ll f(ll N) {
    return g1(N) - g2(N);
}

int main(){
    ll N, K;
    cin >> N >> K;
    ll ans = N;
    ll pre = INF;
    REP(i, K) {
        if(pre == ans) {
            break;
        } else {
            pre = ans;
        }
        ans = f(ans);
    }
    cout << ans << endl;
    return 0;
}