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

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    map<char, ll> m;
    for(const char &s : S) {
        m[s]++;
    }
    mint ans = 1;
    for (const pair<char, ll> &elm : m) {
        ans *= (elm.second + 1);
    }
    ans--;
    cout << ans.val() << endl;
    return 0;
}