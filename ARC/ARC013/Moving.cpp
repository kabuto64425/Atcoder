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
    ll C;
    cin >> C;
    vector<vector<ll>> val(C, vector<ll>(3));
    for(auto &v: val) {
        for(auto &elm : v) {
            cin >> elm;
        }
        sort(v.begin(), v.end());
    }
    ll x = 0;
    ll y = 0;
    ll z = 0;
    for(const auto &v: val) {
        x = max(x, v[0]);
        y = max(y, v[1]);
        z = max(z, v[2]);
    }
    cout << x * y * z << endl;
    return 0;
}