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
    vector<ll> C(N);
    for(ll i = 1; i <= N / 2; i++) {
        B.at(i) = A.at(i - 1);
    }
    for(ll i = 1; i <= N / 2; i++) {
        C.at(i) = A.at(N - i);
    }
    dsu d(220000);
    for(ll i = 1; i <= N / 2; i++) {
        if(B.at(i) == C.at(i)) {
            continue;
        }
        d.merge(B.at(i), C.at(i));
    }
    ll ans = 0;
    vector<bool> vec(220000, false);
    for(ll i = 1; i < 220000; i++) {
        if(!vec.at(d.leader(i))) {
            ans += d.size(i) - 1;
            vec.at(d.leader(i)) = true;
        }
    }
    cout << ans << endl;
    return 0;
}