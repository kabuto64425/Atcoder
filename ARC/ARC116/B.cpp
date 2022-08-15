#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
    sort(A.begin(), A.end(), greater<ll>());
    mint base = 0;
    mint ans = 0;
    for(ll i = 1; i < N; i++) {
        base = A.at(i - 1) + base * 2;
        ans += A.at(i) * base;
    }
    for(ll i = 0; i < N; i++) {
        ans += A.at(i) * A.at(i);
    }
    cout << ans.val() << endl;
    return 0;
}