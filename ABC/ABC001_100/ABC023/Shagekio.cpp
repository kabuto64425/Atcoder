
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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> HS(N);
    REP(i, N) {
        cin >> HS.at(i).first >> HS.at(i).second;
    }

    ll ok = 1000000000 + 1000000000 * (N - 1);
    ll ng = 0;

    while(abs(ng - ok) != 1) {
        ll mid = (ok + ng) / 2;

        vector<ll> count(N, 0);
        bool flag = true;
        REP(j, N) {
            if(mid < HS.at(j).first) {
                flag = false;
                break;
            }
            ll time = (mid - HS.at(j).first) / HS.at(j).second;
            count.at(min(time, N - 1))++;
        }
        if(!flag) {
            ng = mid;
            continue;
        }
        REP(j, N - 1) {
            count.at(j + 1) += count.at(j);
        }
        REP(j, N) {
            if(j + 1 < count.at(j)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
}