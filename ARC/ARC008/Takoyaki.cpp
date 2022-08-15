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
    ll N, M;
    cin >> N >> M;
    string name;
    string kit;
    cin >> name;
    cin >> kit;
    
    map<char, ll> nameMap;
    for(const char &c : name) {
        nameMap[c] += 1;
    }

    map<char, ll> kitMap;
    for(const char &c : kit) {
        kitMap[c] += 1;
    }

    ll ans = 0;

    for (auto elm : nameMap) {
        if(kitMap[elm.first] == 0) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, (elm.second + (kitMap[elm.first] - 1)) / kitMap[elm.first]);
    }
    cout << ans << endl;
    return 0;
}