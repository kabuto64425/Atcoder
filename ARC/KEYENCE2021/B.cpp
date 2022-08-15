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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }

    vector<ll> bucket(330000, 0);
    for(const ll &elm : a) {
        bucket.at(elm)++;
    }

    ll ans = 0;

    ll current = INF;
    for(ll i = 0; i <= N + 1; i++) {
        if(i >= 1 and current > min(bucket.at(i), K)) {
            ll x = current - min(bucket.at(i), K);
            ans += x * i;
        }
        current = min({bucket.at(i), K, current});
    }

    cout << ans << endl;

    return 0;
}