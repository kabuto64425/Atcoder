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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> B(M);
    for(ll &b : B) {
        cin >> b;
    }
    sort(B.begin(), B.end());
    ll ans = INF;
    for(const ll &a : A) {
        ll index = lower_bound(B.begin(), B.end(), a) - B.begin();
        if(index == 0) {
            ans = min(ans, abs(a - B.at(index)));
            continue;
        }
        if(index == M) {
            ans = min(ans, abs(a - B.at(index - 1)));
            continue;
        }
        ans = min(ans, abs(a - B.at(index)));
        ans = min(ans, abs(a - B.at(index - 1)));
        continue;
    }
    cout << ans << endl;
    return 0;
}