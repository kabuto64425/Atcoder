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
    ll A, B, K;
    cin >> A >> B >> K;
    set<ll> ans;
    for(ll i = A; i <= min(B, A + K - 1); i++) {
        ans.insert(i);
    }
    for(ll i = max(A, B - K + 1); i <= B; i++) {
        ans.insert(i);
    }
    for(ll s : ans) {
        cout << s << endl;
    }
    return 0;
}