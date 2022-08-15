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
    ll N, T;
    cin >> N >> T;
    vector<pair<ll, ll>> AB(N);
    for(auto &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    ll sum = 0;
    for(const auto &ab : AB) {
        sum += ab.first;
    }
    vector<ll> v(N);
    for(ll i = 0; i < N; i++) {
        v.at(i) = AB.at(i).first - AB.at(i).second;
    }
    sort(v.begin(), v.end(), greater<ll>());
    if(sum <= T) {
        cout << 0 << endl;
        return 0;
    }
    for(ll i = 1; i <= N; i++) {
        sum -= v.at(i - 1);
        if(sum <= T) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}