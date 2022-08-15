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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<ll> C(K), D(N - K);
    for(ll i = 0; i < K; i++) {
        C.at(i) = A.at(i);
    }
    for(ll i = 0; i < N - K; i++) {
        D.at(i) = A.at(i + K);
    }
    for(ll i = 1; i < N - K; i++) {
        D.at(i) = max(D.at(i), D.at(i - 1));
    }
    ll ans = INF;
    for(ll i = 0; i < K; i++) {
        ll x = K - i - 1;
        ll y = upper_bound(ALL(D), C.at(i)) - D.begin();
        if(y != N - K) {
            ans = min(ans, x + y);
        }
    }
    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    ans++;
    cout << ans << endl;
    return 0;
}