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
    ll D;
    cin >> D;
    vector<ll> c(26);
    for(ll &elm : c) {
        cin >> elm;
    }
    vector<vector<ll>> s(D, vector<ll>(26));
    for(vector<ll> &vec : s) {
        for(ll &elm : vec) {
            cin >> elm;
        }
    }
    vector<ll> t(D);
    for(ll &elm : t) {
        cin >> elm;
    }
    ll satisfaction = 0;
    vector<ll> last(26, 0);
    for(ll i = 0; i < D; i++) {
        ll type = t.at(i);
        last.at(type - 1) = (i + 1);
        satisfaction += s.at(i).at(type - 1);
        for(ll j = 0; j < 26; j++) {
            satisfaction -= c.at(j) * ((i + 1) - last.at(j));
        }
        cout << satisfaction << endl;
    }
    return 0;
}