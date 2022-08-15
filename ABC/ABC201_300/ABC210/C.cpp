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
    ll N, K;
    cin >> N >> K;
    vector<ll> c(N);
    for(ll &elm : c) {
        cin >> elm;
    }
    map<ll, ll> m;
    ll ans = 0;
    for(ll i = 0; i < K; i++) {
        if(m[c.at(i)] == 0) {
            ans++;
        }
        m[c.at(i)]++;
    }
    ll current = ans;
    for(ll i = 1; i <= N - K; i++) {
        m[c.at(i - 1)]--;
        if(m[c.at(i - 1)] == 0) {
            current--;
        }
        if(m[c.at(i + K - 1)] == 0) {
            current++;
        }
        m[c.at(i + K - 1)]++;
        ans = max(ans, current);
    }
    cout << ans << endl;
    return 0;
}