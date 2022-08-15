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

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    vector<pair<ll, ll>> v(3);
    v.at(0) = {-A, 0};
    v.at(1) = {-B, 1};
    v.at(2) = {-C, 2};
    sort(ALL(v));
    vector<ll> ans(3);
    for(ll i = 0; i < 3; i++) {
        ans.at(v.at(i).second) = i + 1;
    }
    for(ll i = 0; i < 3; i++) {
        cout << ans.at(i) << endl;
    }
    return 0;
}