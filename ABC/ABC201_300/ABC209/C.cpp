#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
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
    vector<ll> C(N);
    for(ll &c : C) {
        cin >> c;
    }
    sort(C.begin(), C.end());
    mint ans = 1;
    for(ll i = 0; i < N; i++) {
        if(C.at(i) - i <= 0) {
            ans = 0;
            break;
        }
        ans *= (C.at(i) - i);
    }
    cout << ans.val() << endl;
    return 0;
}