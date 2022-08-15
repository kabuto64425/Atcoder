#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string S;
    cin >> S;
    map<char, ll> m;
    m['c'] = 1;
    m['h'] = 2;
    m['o'] = 3;
    m['k'] = 4;
    m['u'] = 5;
    m['d'] = 6;
    m['a'] = 7;
    m['i'] = 8;
    vector<mint> dp(9, 0);
    dp.at(0) = 1;
    for(const char &c : S) {
        if(!m.count(c)) {
            continue;
        }
        ll index = m[c];
        dp.at(index) += dp.at(index - 1);
    }
    cout << dp.at(8).val() << endl;
    return 0;
}