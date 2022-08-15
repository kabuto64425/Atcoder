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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

void dfs(vector<ll> &vec, ll current) {
    vec.push_back(current);
    if(current > ((ll)1e10)) {
        return;
    }
    if(current % 10 >= 1) {
        dfs(vec, current * 10 + current % 10 - 1);
    }
    dfs(vec, current * 10 + current % 10);
    if(current % 10 <= 8) {
        dfs(vec, current * 10 + current % 10 + 1);
    }
}

int main(){
    ll K;
    cin >> K;
    vector<ll> vec;
    dfs(vec, 1);
    dfs(vec, 2);
    dfs(vec, 3);
    dfs(vec, 4);
    dfs(vec, 5);
    dfs(vec, 6);
    dfs(vec, 7);
    dfs(vec, 8);
    dfs(vec, 9);
    sort(ALL(vec));
    cout << vec.at(K - 1) << endl;
    return 0;
}