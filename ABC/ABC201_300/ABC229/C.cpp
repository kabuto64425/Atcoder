#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N ;i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<pair<ll, ll>> p(N);
    for(ll i = 0; i < N; i++) {
        p.at(i).first = -A.at(i);
        p.at(i).second = B.at(i);
    }
    sort(ALL(p));
    ll ans = 0;
    ll rest = W;
    for(ll i = 0; i < N; i++) {
        ll weight = min(p.at(i).second, rest);
        ans += (-p.at(i).first * weight);
        rest -= weight;
    }
    cout << ans << endl;
    return 0;
}