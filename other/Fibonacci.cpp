#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

ll fibo(ll n, vector<ll> &memo) {
    if(n == 1) {
        return 1;
    }
    if(n == 2) {
        return 1;
    }
    if(memo.at(n) != -1) {
        return memo.at(n);
    }
    return memo.at(n) = fibo(n - 1, memo) + fibo(n - 2, memo);
}

signed main(){
    ll n;
    cin >> n;
    vector<ll> memo(n + 1, -1);
    cout << fibo(n, memo) << endl;
}