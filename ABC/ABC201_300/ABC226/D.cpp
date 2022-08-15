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
    set<pair<ll, ll>> s;
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            ll dx = x.at(i) - x.at(j);
            ll dy = y.at(i) - y.at(j);
            if(dx == 0) {
                ll vx = 0;
                ll vy = ((dy > 0)? 1 : -1);
                if(!s.count({vx, vy})) {
                    s.insert({vx, vy});
                    ans++;
                }
            }
            if(dy == 0) {
                ll vx = ((dx > 0)? 1 : -1);
                ll vy = 0;
                if(!s.count({vx, vy})) {
                    s.insert({vx, vy});
                    ans++;
                }
            }
            ll vx = dx / gcd(dx, dy);
            ll vy = dy / gcd(dx, dy);
            if(!s.count({vx, vy})) {
                s.insert({vx, vy});
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}