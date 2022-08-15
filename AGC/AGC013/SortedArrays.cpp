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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A.at(i);
    }

    ll ans = 1;
    bool first = true;
    bool up = true;
    bool down = true;
    ll current = A.at(0);
    FOR(i, 1, N - 1) {
        if(first) {
            if(A.at(i) != current) {
                if(A.at(i) < current) {
                    up = false;
                } else {
                    down = false;
                }
            }
            first = false;
        } else {
            if(up) {
                if(A.at(i) < current) {
                    up = false;
                }
            }
            if(down) {
                if(A.at(i) > current) {
                    down = false;
                }
            }
        }
        current = A.at(i);
        if(!up && !down) {
            first = true;
            up = true;
            down = true;
            ans++;
        }
    }
    cout << ans << endl;
}