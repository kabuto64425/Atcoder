#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

long double recur(ll X, ll Y, ll Z, vector<vector<vector<long double>>> &memo) {
    if(X == 100 or Y == 100 or Z == 100) {
        return 0;
    }
    if(memo[X][Y][Z] != -1) {
        return memo[X][Y][Z];
    }
    return memo[X][Y][Z] = (X / (long double)(X + Y + Z)) * (recur(X + 1, Y, Z, memo) + 1) + (Y / (long double)(X + Y + Z)) * (recur(X, Y + 1, Z, memo) + 1) + (Z / (long double)(X + Y + Z)) * (recur(X, Y, Z + 1, memo) + 1);
}

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<long double>>> memo(101, vector<vector<long double>>(101, vector<long double>(101, -1)));
    cout << fixed << setprecision(20) << recur(A, B, C, memo) << endl;
    return 0;
}