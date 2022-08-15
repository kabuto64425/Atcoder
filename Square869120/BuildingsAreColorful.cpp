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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    REP(i, N) {
        cin >> a.at(i);
    }

    ll first = a.at(0);
    ll ans = INF;
    REP(bit, (1 << (N - 1))) {
        ll cost = 0;
        ll maxhight = first;
        ll maxhight2 = 0;
        if((ll)__builtin_popcountll(bit) < K - 1) {
            continue;
        }
        REP(i, N - 1) {
            if(bit & (1 << i)) {
                ll index = i + 1;
                ll hight = a.at(index);
                if(maxhight < maxhight2) {
                    cost += maxhight2 - maxhight;
                    maxhight = maxhight2;
                }
                
                if(hight <= maxhight) {
                    maxhight = maxhight + 1;
                    cost += maxhight - hight;
                } else {
                    maxhight = hight;
                }
                
                maxhight2 = 0;
            } else {
                ll index = i + 1;
                ll hight = a.at(index);
                maxhight2 = max(maxhight2, hight);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}