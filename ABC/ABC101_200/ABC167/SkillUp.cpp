#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, M, X;
    cin >> N >> M >> X;
    vector<pair<ll, vector<ll>>> CA(N);
    REP(i, N) {
        cin >> CA.at(i).first;
        vector<ll> A(M);
        REP(j, M) {
            cin >> A.at(j);
        }
        CA.at(i).second = A;
    }

    ll ans = -1;

    REP(bit, (1 << N)) {
        vector<ll> status(M, 0);
        ll money = 0;
        REP(i, N) {
            if(bit & (1 << i)) {
                money += CA.at(i).first;
                REP(j, M) {
                    status.at(j) += CA.at(i).second.at(j);
                }
            }
        }
        bool flag = true;
        REP(i, M) {
            if(status.at(i) < X) {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(ans == -1) {
                ans = money;
            } else {
                ans = min(ans, money);
            }
        }
    }

    cout << ans << endl;
}