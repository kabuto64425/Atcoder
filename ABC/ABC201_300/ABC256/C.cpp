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

ll h1, h2, h3;
ll w1, w2, w3;

void dfs(vector<ll> &v, ll &ans) {
    if(v.size() == 4) {
        ll a1 = v.at(0);
        ll a2 = v.at(1);

        ll a3 = h1 - a1 - a2;

        if(a3 <= 0) {
            return;
        }

        ll a4 = v.at(2);
        ll a5 = v.at(3);

        ll a6 = h2 - a4 - a5;
        if(a6 <= 0) {
            return;
        }

        ll a7 = w1 - a1 - a4;
        ll a8 = w2 - a2 - a5;
        if(a7 <= 0 or a8 <= 0) {
            return;
        }

        ll a91 = h3 - a7 - a8;
        ll a92 = w3 - a3 - a6;
        if(a91 <= 0 or a92 <= 0) {
            return;
        }
        if(a91 == a92) {
            ans++;
        }
        return;
    }
    for(ll i = 1; i <= 30 ; i++) {
        v.push_back(i);
        dfs(v, ans);
        v.pop_back();
    }
}

int main(){
    cin >> h1 >> h2 >> h3;
    cin >> w1 >> w2 >> w3;
    ll ans = 0;
    vector<ll> v;
    dfs(v, ans);
    cout << ans << endl;
    return 0;
}