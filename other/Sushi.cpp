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

long double recur(ll N, vector<ll> a, map<vector<ll>, long double> &memo) {
    if(memo.count(a)) {
        return memo[a];
    }
    if(all_of(a.begin(), a.end(), [](ll x) { return x == 0;})) {
        return memo[a] = 0;
    }
    long double ret = 0;
    for(ll i = 0; i < N; i++) {
        vector<ll> temp = a;
        temp.at(i) = max(temp.at(i) - 1, 0LL);
        ret += (recur(N, temp, memo) + 1) / (long double) N;
    }
    return memo[a] = ret;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    map<vector<ll>, long double> memo;
    cout << recur(N, a, memo) << endl;
    return 0;
}