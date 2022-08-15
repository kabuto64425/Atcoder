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

void dfs(ll rest, ll m, vector<ll> &vec) {
    if(rest == 0) {
        for(ll &elm : vec) {
            cout << (char)('a' + (char)elm);
        }
        cout << endl;
        return;
    }
    for(ll i = 0; i < m + 1; i++) {
        vec.push_back(i);
        dfs(rest - 1, max(i + 1, m), vec);
        vec.pop_back();
    }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> vec;
    dfs(N, 0, vec);
    return 0;
}