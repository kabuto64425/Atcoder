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
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; i ++) {
        cin >> X.at(i) >> Y.at(i);
    }
    set<pair<ll, ll>> s;
    for(ll i = 0; i < N; i ++) {
        s.insert({X.at(i), Y.at(i)});
    }
    ll ans = 0;
    for(ll i = 0; i <= N - 2; i++) {
        for(ll j = i + 1; j <= N - 1; j++) {
            ll x1 = X.at(i);
            ll y1 = Y.at(i);
            ll x2 = X.at(j);
            ll y2 = Y.at(j);
            if(x1 == x2 or y1 == y2) {
                continue;
            }
            if(s.count({x2, y1}) and s.count({x1, y2})) {
                ans++;
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}