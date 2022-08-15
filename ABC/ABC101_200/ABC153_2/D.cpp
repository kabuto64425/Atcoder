#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll recur(ll H, map<ll, ll> &memo) {
    if(H == 1) {
        return 1;
    }
    if(memo.count(H)) {
        return memo[H];
    }
    return memo[H] = recur(H / 2, memo) + recur(H / 2, memo) + 1;
}

int main(){
    ll H;
    cin >> H;
    map<ll, ll> memo;
    cout << recur(H, memo) << endl;
    return 0;
}