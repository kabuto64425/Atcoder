#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

void rec(ll N, ll now, ll &ans) {
    if(now > N) {
        return;
    }
    bool seven = false;
    bool five = false;
    bool three = false;
    ll num = now;
    while(num > 0) {
        if(num % 10 == 7) {
            seven = true;
        } else if(num % 10 == 5) {
            five = true;
        } else if(num % 10 == 3) {
            three = true;
        }
        num = num / 10;
    }
    if(seven && five && three) {
        ans++;
    }
    rec(N, now * 10 + 7, ans);
    rec(N, now * 10 + 5, ans);
    rec(N, now * 10 + 3, ans);
}

signed main(){
    ll N;
    cin >> N;
    ll ans = 0;
    rec(N, 0, ans);
    cout << ans << endl;
}