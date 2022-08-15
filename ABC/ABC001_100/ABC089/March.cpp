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
    vector<string> S(N);
    REP(i, N) {
        cin >> S.at(i);
    }

    ll M = 0;
    ll A = 0;
    ll R = 0;
    ll C = 0;
    ll H = 0;

    REP(i, N) {
        if(S.at(i).at(0) == 'M') {
            M++;
        } else if(S.at(i).at(0) == 'A') {
            A++;
        } else if(S.at(i).at(0) == 'R') {
            R++;
        } else if(S.at(i).at(0) == 'C') {
            C++;
        } else if(S.at(i).at(0) == 'H') {
            H++;
        }
    }

    ll ans = 0;

    ans += M * A * R;
    ans += M * A * C;
    ans += M * A * H;
    ans += M * R * C;
    ans += M * R * H;
    ans += M * C * H;
    ans += A * R * C;
    ans += A * R * H;
    ans += A * C * H;
    ans += R * C * H;

    cout << ans << endl;
}