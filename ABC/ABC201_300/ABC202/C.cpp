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
    vector<ll> A(N + 1);
    vector<ll> B(N + 1);
    vector<ll> C(N + 1);
    for(ll i = 1; i <= N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 1; i <= N; i++) {
        cin >> B.at(i);
    }
    for(ll i = 1; i <= N; i++) {
        cin >> C.at(i);
    }
    vector<ll> bucket1(N + 1, 0);
    vector<ll> bucket2(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        bucket1.at(A.at(i))++;
    }
    for(ll i = 1; i <= N; i++) {
        bucket2.at(B.at(C.at(i)))++;
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        ans += bucket1.at(i) * bucket2.at(i);
    }
    cout << ans << endl;
    return 0;
}