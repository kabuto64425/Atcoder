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
    string S;
    cin >> S;

    vector<ll> A(N, 0);
    vector<ll> G(N, 0);
    vector<ll> C(N, 0);
    vector<ll> T(N, 0);

    REP(i, N) {
        char c = S.at(i);
        A.at(i) = A.at(max(i - 1, (ll) 0));
        G.at(i) = G.at(max(i - 1, (ll) 0));
        C.at(i) = C.at(max(i - 1, (ll) 0));
        T.at(i) = T.at(max(i - 1, (ll) 0));
        if(c == 'A') {
            A.at(i)++;
        } else if(c == 'G') {
            G.at(i)++;
        } else if(c == 'C') {
            C.at(i)++;
        } else if(c == 'T') {
            T.at(i)++;
        }
    }

    ll ans = 0;

    for(ll i = 0; i < N - 1; i++) {
        for(ll j = i + 1; j < N; j++) {
            if(i == 0) {
                if((A.at(j)) == (T.at(j)) && (G.at(j)) == (C.at(j))) {
                    ans++;
                }
            } else {
                if((A.at(j) - A.at(i - 1)) == (T.at(j) - T.at(i - 1)) && (G.at(j) - G.at(i - 1)) == (C.at(j) - C.at(i - 1))) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}