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

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }

    if(K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    vector<ll> counts(330);
    for(ll i = 0; i < N; i++) {
        for(ll j = i + 1; j < N; j++) {
            ll vx1 = X.at(j) - X.at(i);
            ll vy1 = Y.at(j) - Y.at(i);
            ll count = 0;
            for(ll k = 0; k < N; k++) {
                ll vx2 = X.at(k) - X.at(i);
                ll vy2 = Y.at(k) - Y.at(i);
                if(vx1 * vy2 == vx2 * vy1) {
                    count++;
                }
            }
            counts.at(count)++;
        }
    }

    ll ans = 0;
    for(ll i = K; i <= 300; i++) {
        ans += counts.at(i) / (i * (i - 1) / 2);
    }
    cout << ans << endl;
    return 0;
}