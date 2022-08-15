#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> S(N);
    for(ll &s : S) {
        cin >> s;
    }
    set<ll> x;
    for(ll a = 1; a <= 334; a++) {
        for(ll b = 1; b <= 334; b++) {
            x.insert(4 * a * b + 3 * a + 3 * b);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(!x.count(S.at(i))) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}