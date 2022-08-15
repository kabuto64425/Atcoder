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

ll func(pair<ll, ll> p) {
    ll a = p.first;
    ll res1 = 0;
    while(a > 0) {
        res1++;
        a /= 10;
    }
    ll b = p.second;
    ll res2 = 0;
    while(b > 0) {
        res2++;
        b /= 10;
    }
    return max(res1, res2);
}

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> vec;
    for(ll i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            vec.push_back({i, N / i});
        }
    }

    ll ans = INF;
    for(const auto &elm : vec) {
        ans = min(ans, func(elm));
    }
    cout << ans << endl;
    return 0;
}