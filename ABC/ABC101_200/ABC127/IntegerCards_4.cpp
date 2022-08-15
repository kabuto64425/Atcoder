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
    map<ll, ll, greater<ll>> m;
    vector<ll> vec;
    for(ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        m[a]++;
    }
    for(ll i = 0; i < M; i++) {
        ll b, c;
        cin >> b >> c;
        m[c] += b;
    }
    ll ans = 0;
    ll cur = 0;
    for (const auto& p : m) {
        ans += p.first * min(N - cur, p.second);
        cur = min(N, cur + p.second);
    }
    cout << ans << endl;
    return 0;
}