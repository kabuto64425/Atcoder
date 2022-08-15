#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> gcdFromLeft(N);
    gcdFromLeft.at(0) = A.at(0);
    for(ll i = 1; i < N; i++) {
        gcdFromLeft.at(i) = gcd(A.at(i), gcdFromLeft.at(i - 1));
    }

    vector<ll> gcdFromRight(N);
    gcdFromRight.at(N - 1) = A.at(N - 1);
    for(ll i = N - 2; i >= 0; i--) {
        gcdFromRight.at(i) = gcd(A.at(i), gcdFromRight.at(i + 1));
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(i == 0) {
            ans = max(ans, gcdFromRight.at(1));
            continue;
        }
        if(i == N - 1) {
            ans = max(ans, gcdFromLeft.at(N - 2));
            continue;
        }
        ans = max(ans, gcd(gcdFromLeft.at(i - 1), gcdFromRight.at(i + 1)));
    }

    cout << ans << endl;
    return 0;
}