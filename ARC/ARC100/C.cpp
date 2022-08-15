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
    for(ll i = 0; i < N ; i++) {
        B.at(i) = A.at(i) - (i + 1);
    }
    sort(B.begin(), B.end());
    ll b;
    if(N % 2 == 1) {
        b = B.at(N / 2);
    } else {
        b = (B.at((N - 1) / 2) + B.at(N / 2)) / 2;
    }
    ll ans = 0;
    for(ll i = 0; i < N ; i++) {
        ans += abs(B.at(i) - b);
    }
    cout << ans << endl;
    return 0;
}