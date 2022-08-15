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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(M);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    ll K;
    cin >> K;
    vector<pair<ll, ll>> CD(K);
    for(pair<ll, ll> &cd : CD) {
        cin >> cd.first >> cd.second;
    }

    ll ans = 0;

    for(ll bit = 1; bit < (1 << K); bit++) {
        vector<ll> bucket(N + 1, 0);
        for(ll i = 0; i < K; i++) {
            if(bit & (1 << i)) {
                bucket.at(CD.at(i).first)++;
            } else {
                bucket.at(CD.at(i).second)++;
            }
        }
        ll current = 0;
        for(const pair<ll, ll> &ab : AB) {
            if(bucket.at(ab.first) >= 1 and bucket.at(ab.second) >= 1) {
                current++;
            }
        }
        ans = max(ans, current);
    }
    cout << ans << endl;
    return 0;
}