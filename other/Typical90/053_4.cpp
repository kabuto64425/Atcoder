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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll idx[1609];

ll Ask(ll pos) {
    if (idx[pos] == -1) {
        cout << "? " << pos << endl;
        ll t; cin >> t;
        idx[pos] = t;
        return t;
    }
    return idx[pos];
}

int main(){
    ll fib[16] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };
    ll T;
    cin >> T;
    for(ll t = 0; t < T; t++) {
        ll N;
        cin >> N;
        
        ll ans = 0;

        for (ll i = 0; i <= N; i++) {
            idx[i] = -1;
        }
        for (ll i = N + 1; i <= 1600; i++) {
            idx[i] = -i;
        }

        if (N <= 5) {
            for (ll i = 1; i <= N; i++) ans = max(ans, Ask(i));
        } else {
            ll cl = 0, cr = 1597, dl = 610, dr = 987;
            ll el = Ask(dl);
            ll er = Ask(dr);
            ans = max({ ans, el, er });

            if (el < er) {
                cl = dl;
                dl = dr;
                dr = -1;
                el = er;
                er = -1;
            } else {
                cr = dr;
                dr = dl;
                dl = -1;
                er = el;
                el = -1;
            }

            for (ll i = 12; i >= 0; i--) {
                if (dl == -1) {
                    dl = cl + fib[i];
                    el = Ask(dl);
                } else if (dr == -1) {
                    dr = cr - fib[i];
                    er = Ask(dr);
                }
                ans = max({ ans, el, er });
                if (el < er) {
                    cl = dl;
                    dl = dr;
                    dr = -1;
                    el = er;
                    er = -1;
                } else {
                    cr = dr;
                    dr = dl;
                    dl = -1;
                    er = el; 
                    el = -1;
                }
            }
            for (ll i = cl + 1; i <= cr - 1; i++) {
                ans = max(ans, Ask(i));
            }
        }
        cout << "! " << ans << endl;
    }
    return 0;
}