#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

mint solver(ll N, vector<pair<ll, ll>> AB) {
    sort(ALL(AB));
    mint ans = 0;
    vector<vector<mint>> dp(N + 1, vector<mint>(5500, 0));
    vector<vector<mint>> csum(N + 1, vector<mint>(5500, 0));
    dp.at(0).at(0) = 1;
    for(ll j = 0; j <= 5000; j++) {
        csum.at(0).at(j) = 1;
    }
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 5000; j++) {
            dp.at(i).at(j) += dp.at(i - 1).at(j);
            if(j - AB.at(i - 1).second >= 0) {
                dp.at(i).at(j) += dp.at(i - 1).at(j - AB.at(i - 1).second);
            }
        }
        for(ll j = 0; j <= 5000; j++) {
            csum.at(i).at(j) = dp.at(i).at(j);
        }
        for(ll j = 1; j <= 5000; j++) {
            csum.at(i).at(j) += csum.at(i).at(j - 1);
        }
        if(AB.at(i - 1).first - AB.at(i - 1).second >= 0) {
            ans += (csum.at(i - 1).at(AB.at(i - 1).first - AB.at(i - 1).second));
        }
    }
    return ans;
}

ll solver2(ll N, vector<pair<ll, ll>> AB) {
    ll ans = 0;
    for(ll bit = 1; bit < (1 << N); bit++) {
        ll m = 0;
        ll sum = 0;
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                m = max(m, AB.at(i).first);
                sum += AB.at(i).second;
            }
        }
        if(m >= sum) {
            ans++;
        }
    }
    return ans;
}

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> AB(N);
    for(ll i = 0; i < N; i++) {
        cin >> AB.at(i).first;
    }
    for(ll i = 0; i < N; i++) {
        cin >> AB.at(i).second;
    }

    cout << solver(N, AB).val() << endl;
    //cout << solver2(N, AB) << endl;
    
    return 0;
}