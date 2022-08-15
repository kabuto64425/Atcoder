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
    vector<ll> m(N, 0);
    m.at(0) = A.at(0);
    for(ll i = 1; i < N; i++) {
        m.at(i) = max(A.at(i), m.at(i - 1));
    }
    vector<ll> csum(N, 0);
    csum.at(0) = A.at(0);
    for(ll i = 1; i < N; i++) {
        csum.at(i) = csum.at(i - 1) + A.at(i);
    }
    ll base = 0;
    for(ll i = 0; i < N; i++) {
        base += csum.at(i);
        cout << base + m.at(i) * (i + 1) << endl;
    }
    return 0;
}