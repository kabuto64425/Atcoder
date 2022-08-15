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
    vector<pair<ll, ll>> AB(N);
    for(auto &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    ll aoki = 0;
    for(const auto &ab : AB) {
        aoki += ab.first;
    }
    vector<ll> score(N);
    for(ll i = 0; i < N; i++) {
        score.at(i) = AB.at(i).first * 2 + AB.at(i).second;
    }
    sort(score.begin(), score.end(), greater<ll>());
    ll ans = 0;
    ll current = 0;
    while(true) {
        if(current > aoki) {
            break;
        }
        current += score.at(ans);
        ans++;
    }
    cout << ans << endl;
    return 0;
}