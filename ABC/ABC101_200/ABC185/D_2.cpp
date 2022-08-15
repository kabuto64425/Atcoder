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
    vector<ll> A(M);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> blue(M + 2);
    blue.at(0) = 0;
    for(ll i = 1; i <= M; i++) {
        blue.at(i) = A.at(i - 1);
    }
    blue.at(M + 1) = N + 1;
    sort(blue.begin(), blue.end());
    ll w = INF;
    for(ll i = 1; i <= M + 1; i++) {
        ll c = blue.at(i) - blue.at(i - 1) - 1;
        if(c >= 1) {
            w = min(w, c);
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= M + 1; i++) {
        ll c = blue.at(i) - blue.at(i - 1) - 1;
        ans += (c + (w - 1)) / w;
    }
    cout << ans << endl;
    return 0;
}