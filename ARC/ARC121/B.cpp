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
    vector<ll> a(N * 2);
    vector<char> c(N * 2);
    for(ll i = 0; i < N * 2; i++) {
        cin >> a.at(i) >> c.at(i);
    }
    vector<ll> Rs, Gs, Bs;
    for(ll i = 0; i < N * 2; i++) {
        if(c.at(i) == 'R') {
            Rs.push_back(a.at(i));
        }
        if(c.at(i) == 'G') {
            Gs.push_back(a.at(i));
        }
        if(c.at(i) == 'B') {
            Bs.push_back(a.at(i));
        }
    }
    sort(ALL(Rs));
    sort(ALL(Gs));
    sort(ALL(Bs));
    if(Rs.size() % 2 == 0 and Gs.size() % 2 == 0 and Bs.size() % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    if(Rs.size() % 2 == 0) {
        vector<ll> &V1 = Gs;
        vector<ll> &V2 = Bs;
        ll ans = INF;
        for(ll elm : V1) {
            ll i = lower_bound(ALL(V2), elm) - V2.begin();
            if(i < V2.size()) {
                ans = min(ans, abs(V2.at(i) - elm));
            }
            if(i >= 1) {
                ans = min(ans, abs(V2.at(i - 1) - elm));
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(Gs.size() % 2 == 0) {
        vector<ll> &V1 = Rs;
        vector<ll> &V2 = Bs;
        ll ans = INF;
        for(ll elm : V1) {
            ll i = lower_bound(ALL(V2), elm) - V2.begin();
            if(i < V2.size()) {
                ans = min(ans, abs(V2.at(i) - elm));
            }
            if(i >= 1) {
                ans = min(ans, abs(V2.at(i - 1) - elm));
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(Bs.size() % 2 == 0) {
        vector<ll> &V1 = Gs;
        vector<ll> &V2 = Rs;
        ll ans = INF;
        for(ll elm : V1) {
            ll i = lower_bound(ALL(V2), elm) - V2.begin();
            if(i < V2.size()) {
                ans = min(ans, abs(V2.at(i) - elm));
            }
            if(i >= 1) {
                ans = min(ans, abs(V2.at(i - 1) - elm));
            }
        }
        cout << ans << endl;
        return 0;
    }
    return 0;
}