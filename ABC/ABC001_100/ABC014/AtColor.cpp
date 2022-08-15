#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ab(n);
    for(auto &elm : ab) {
        cin >> elm.first >> elm.second;
    }
    vector<ll> colors(1100000, 0);
    for(const auto &elm : ab) {
        colors.at(elm.first)++;
        colors.at(elm.second + 1)--;
    }
    for(ll i = 0; i < 1000020; i++) {
        colors.at(i + 1) += colors.at(i);
    }
    ll ans = 0;
    for(ll i = 0; i < 1000020; i++) {
        ans = max(ans, colors.at(i));
    }
    cout << ans << endl;
    return 0;
}