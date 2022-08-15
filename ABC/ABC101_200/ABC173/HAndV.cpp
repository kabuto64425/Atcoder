#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> c(H);
    REP(i, H) {
        cin >> c.at(i);
    }

    ll ans = 0;

    REP(bit, (1<<(H + W))) {
        vector<string> temp = c;
        REP(i, H + W) {
            if(bit & (1 << i)) {
                if(i < H) {
                    REP(j, W) {
                        temp.at(i).at(j) = 'R';
                    }
                } else {
                    REP(j, H) {
                        temp.at(j).at(i - H) = 'R';
                    }
                }
            }
        }
        ll countB = 0;
        REP(i, H) {
            REP(j, W) {
                if(temp.at(i).at(j) == '#') {
                    countB++;
                }
            }
        }
        if(countB == K) {
            ans++;
        }
    }

    cout << ans << endl;
}