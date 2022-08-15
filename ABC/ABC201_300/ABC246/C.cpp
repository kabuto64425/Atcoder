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
    ll N, K, X;
    cin >> N >> K >> X;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ll rest = K;
    for(ll i = 0; i < N; i++) {
        if(A.at(i) >= X) {
            ll k = min(rest, A.at(i) / X);
            rest = rest - k;
            A.at(i) = A.at(i) - k * X;
        }
        if(rest == 0) {
            break;
        }
    }
    sort(ALL(A), greater<ll>());
    for(ll i = 0; i < N; i++) {
        if(rest == 0) {
            break;
        }
        A.at(i) = 0;
        rest--;
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ans += A.at(i);
    }
    cout << ans << endl;
    return 0;
}