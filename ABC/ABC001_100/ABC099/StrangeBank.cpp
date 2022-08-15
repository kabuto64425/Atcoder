#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

ll rec(ll n, vector<ll> &memo) {
    if(n == 0) {
        return 0;
    }
    if(memo[n] != -1) {
        return memo[n];
    }

    ll res = INF;

    for(ll pow6 = 1; pow6 <= n; pow6 *= 6) {
        res = min(res, rec(n - pow6, memo) + 1);
    }

    for(ll pow9 = 1; pow9 <= n; pow9 *= 9) {
        res = min(res, rec(n - pow9, memo) + 1);
    }

    return memo[n] = res;
}

signed main(){
    ll N;
    cin >> N;
    vector<ll> memo(N + 1, -1);
    cout << rec(N, memo) << endl;
}