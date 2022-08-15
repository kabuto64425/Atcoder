#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> xyh(N);

    REP(i, N) {
         cin >> get<0>(xyh.at(i)) >> get<1>(xyh.at(i)) >> get<2>(xyh.at(i));
    }

    FOR(cx, 0, 100) {
        FOR(cy, 0, 100) {
            ll H;
            FOR(i, 0, N - 1) {
                if(get<2>(xyh.at(i)) > 0) {
                    H = get<2>(xyh.at(i)) + abs(get<0>(xyh.at(i)) - cx) + abs(get<1>(xyh.at(i)) - cy);
                    break;
                }
            }
            bool flag = true;
            FOR(i, 0, N - 1) {
                if(get<2>(xyh.at(i)) != max(H - abs(get<0>(xyh.at(i)) - cx) - abs(get<1>(xyh.at(i)) - cy), (ll)0)) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
}