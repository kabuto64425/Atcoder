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
    vector<ll> A(N + 1);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    A.at(N) = 0;
    sort(ALL(A), greater<ll>());
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        ll d = A.at(i - 1) - A.at(i);
        if(K >= d * i) {
            ans += (A.at(i - 1) + A.at(i) + 1) * d / 2 * i;
            K -= d * i;
        } else {
            ll count = K / i;
            ans += (A.at(i - 1) + A.at(i - 1) - count + 1) * count / 2 * i;
            ll m = K % i;
            ans += (A.at(i - 1) - count) * m;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}