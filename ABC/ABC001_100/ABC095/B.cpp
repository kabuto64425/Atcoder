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
    ll N, X;
    cin >> N >> X;
    vector<ll> m(N);
    for(ll &elm : m) {
        cin >> elm;
    }
    ll ans = 0;
    ll mi = INF;
    for(const ll &elm : m) {
        X -= elm;
        ans++;
        mi = min(mi, elm);
    }
    ans += X / mi;
    cout << ans << endl;
    return 0;
}