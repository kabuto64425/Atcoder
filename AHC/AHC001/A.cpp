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
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> xyr(n);
    for(auto &elm : xyr) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }

    vector<bool> flags(10000, true);
    vector<ll> columns(n, -1);
    for(ll i = 0; i < n; i++) {
        if(flags.at(get<0>(xyr.at(i)))) {
            flags.at(get<0>(xyr.at(i))) = false;
            columns.at(i) = get<0>(xyr.at(i));
        }
    }
    queue<ll> que;
    for(ll i = 0; i < 10000; i++) {
        if(flags.at(i)) {
            que.push(i);
        }
    }
    for(ll i = 0; i < n; i++) {
        if(columns.at(i) == -1) {
            columns.at(i) = que.front();
            que.pop();
        }
    }
    for(ll i = 0; i < n; i++) {
        cout << columns.at(i) << " " << 0 << " " << columns.at(i) + 1 << " " << 10000 << endl;
    }
    return 0;
}