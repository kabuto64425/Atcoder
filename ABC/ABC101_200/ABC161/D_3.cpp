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

void dfs(ll current, vector<ll> &vec) {
    vec.push_back(current);
    if(current > (ll)1e10) {
        return;
    }
    ll last = current % 10;
    if(last >= 1) {
        dfs(current * 10 + last - 1, vec);
    }
    dfs(current * 10 + last, vec);
    if(last <= 8) {
        dfs(current * 10 + last + 1, vec);
    }
}

int main(){
    ll K;
    cin >> K;
    vector<ll> v;
    for(ll i = 1; i <= 9; i++) {
        ll count = 0;
        dfs(i, v);
    }
    sort(ALL(v));
    cout << v.at(K - 1) << endl;
    return 0;
}