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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    reverse(ALL(A));
    vector<ll> csum(N + 1, 0);
    for(ll i = 0; i < N; i++) {
        csum.at(i + 1) = csum.at(i) + A.at(i);
    }

    for(ll i = 0; i < N + 1; i++) {
        csum.at(i) %= 360;
    }

    sort(ALL(csum));

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ans = max(ans, csum.at(i + 1) - csum.at(i));
    }

    ans = max(ans, 360 - csum.at(N));

    cout << ans << endl;

    return 0;
}