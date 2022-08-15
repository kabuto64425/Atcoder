#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<string> s(N);
    for(string &elm : s) {
        cin >> elm;
    }
    ll M;
    cin >> M;
    vector<string> t(M);
    for(string &elm : t) {
        cin >> elm;
    }
    map<string, ll> m;
    for(const string &elm : s) {
        m[elm]++;
    }
    for(const string &elm : t) {
        m[elm]--;
    }
    ll ans = 0;
    for (auto elm : m) {
        ans = max(ans, elm.second);
    }
    cout << ans << endl;
    return 0;
}