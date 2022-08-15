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
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> B(N);
    for(ll &b : B) {
        cin >> b;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ans += abs(A.at(i) - B.at(i));
    }
    cout << ans << endl;
    return 0;
}