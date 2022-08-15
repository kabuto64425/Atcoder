#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll K;
    cin >> K;
    string S, T;
    cin >> S >> T;
    vector<ll> takahashi(9);
    vector<ll> aoki(9);
    for(ll i = 0; i < 4; i++) {
        takahashi.at(S.at(i) - '0' - 1)++;
        aoki.at(T.at(i) - '0' - 1)++;
    }
    long double ans = 0;
    for(ll i = 0; i < 9; i++) {
        for(ll j = 0; j < 9; j++) {
            ll takahashiScore = 0;
            ll aokiScore = 0;
            for(ll k = 0; k < 9; k++) {
                if(i == k) {
                    takahashiScore += (k + 1) * pow(10, takahashi.at(k) + 1);
                } else {
                    takahashiScore += (k + 1) * pow(10, takahashi.at(k));
                }
                if(j == k) {
                    aokiScore += (k + 1) * pow(10, aoki.at(k) + 1);
                } else {
                    aokiScore += (k + 1) * pow(10, aoki.at(k));
                }
            }
            if(takahashiScore > aokiScore) {
                long double x = (K - takahashi.at(i) - aoki.at(i)) / (long double)(9 * K - 8);
                x *= (K - takahashi.at(j) - aoki.at(j) - ((i == j)? 1 : 0)) / (long double)(9 * K - 9);
                ans += x;
            }
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}