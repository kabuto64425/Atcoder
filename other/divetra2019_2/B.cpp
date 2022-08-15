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
    ll N;
    cin >> N;
    vector<ll> x(N), y(N);
    for(ll i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i);
    }
    if(N == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll xs = x.at(0);
    ll ys = y.at(0);
    ll ans = INF;
    set<pair<ll, ll>> s;
    for(ll i = 0; i < N; i++) {
        s.insert({x.at(i), y.at(i)});
    }
    for(ll i = 1; i < N; i++) {
        ll vx = x.at(i) - xs;
        ll vy = y.at(i) - ys;
        ll count = 0;
        for(ll j = 0; j < N; j++) {
            if(s.count({x.at(j) + vx, y.at(j) + vy})) {
                count++;
            }
        }
        ans = min(ans, N - count);
    }
    cout << ans << endl;
    return 0;
}