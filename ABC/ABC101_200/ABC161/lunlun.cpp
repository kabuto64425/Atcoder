#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll K;
    cin >> K;

    queue<ll> que;

    // 要素を追加
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(6);
    que.push(7);
    que.push(8);
    que.push(9);

    ll ans = 0;

    REP(i, K) {
        ans = que.front();
        que.pop();
        if(ans % 10 != 0) {
            que.push(ans * 10 + ans % 10 - 1);
        }
        que.push(ans * 10 + ans % 10);
        if(ans % 10 != 9) {
            que.push(ans * 10 + ans % 10 + 1);
        }
    }

    cout << ans << endl;
}