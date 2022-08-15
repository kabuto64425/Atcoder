#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

ll recur(ll n, vector<ll> &memo) {
    if(memo.at(n) != -1) {
        return memo.at(n);
    }
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 1;
    }
    return memo.at(n) = (recur(n - 1, memo) + recur(n - 2, memo)) % MOD;
}

signed main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M);
    REP(i, M) {
        cin >> a.at(i);
    }
    vector<ll> memo(N + 1, -1);
    REP(i, M) {
        memo.at(a.at(i)) = 0;
    }
    cout << recur(N, memo) << endl;
}