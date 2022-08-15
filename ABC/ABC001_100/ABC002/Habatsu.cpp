#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> xy;
    REP(i, M) {
        ll x, y;
        cin >> x >> y;
        xy.insert({x, y});
    }

    ll ans = 0;

    REP(bit, (1 << N)) {
        vector<ll> giin;
        REP(i, N) {
            if(bit & (1 << i)) {
                giin.push_back(i + 1);
            }
        }
        bool flag = true;
        for(ll i = 0; i < (ll)giin.size() - 1; i++) {
            for(ll j = i + 1; j < (ll)giin.size(); j++) {
                ll x = giin.at(i);
                ll y = giin.at(j);
                if(!xy.count({x, y})) {
                    flag = false;
                }
            }
        }
        if(flag) {
            ans = max(ans, (ll)__builtin_popcountll(bit));
        }
    }
    cout << ans << endl;
}