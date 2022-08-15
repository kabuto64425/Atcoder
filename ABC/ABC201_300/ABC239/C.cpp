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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<ll> dx(8), dy(8);
    dx = {1, 2, 2, 1, -1, -2, -2, -1};
    dy = {2, 1, -1, -2, -2, -1, 1, 2};
    set<pair<ll, ll>> s;
    for(ll i = 0; i < 8; i++) {
        s.insert({x1 + dx.at(i), y1 + dy.at(i)});
    }
    for(ll i = 0; i < 8; i++) {
        if(s.count({x2 + dx.at(i), y2 + dy.at(i)})) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}