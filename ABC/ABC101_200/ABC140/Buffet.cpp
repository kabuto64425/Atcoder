#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N - 1);
    for(ll &a : A) {
        cin >> a;
    }
    for(ll &b : B) {
        cin >> b;
    }
    for(ll &c : C) {
        cin >> c;
    }
    ll ans = 0;
    ans = accumulate(B.begin(), B.end(), 0LL);
    for(ll i = 1; i <= N - 1; i++) {
        if(A.at(i - 1) + 1 == A.at(i)) {
            ans += C.at(A.at(i - 1) - 1);
        }
    }
    cout << ans << endl;
    return 0;
}