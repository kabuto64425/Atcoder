#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll cost(ll i, ll s, const vector<ll> &A) {
    if(s == 0 or s == 4) {
        return A.at(i);
    }
    if(s == 1 or s == 3) {
        if(A.at(i) == 0) {
            return 2;
        }
        if(A.at(i) % 2 == 0) {
            return 0;
        }
        return 1;
    }
    if(A.at(i) % 2 == 1) {
        return 0;
    }
    return 1;
}

int main(){
    ll L;
    cin >> L;
    vector<ll> A(L);
    for(ll &a : A) {
        cin >> a;
    }
    vector<vector<ll>> dp(L + 1, vector<ll>(5, INF));
    dp.at(0).at(0) = 0;
    for(ll i = 1; i <= L; i++) {
        for(ll j = 0; j < 5; j++) {
            for(ll k = j; k < 5; k++) {
                dp.at(i).at(k) = min(dp.at(i).at(k), dp.at(i - 1).at(j) + cost(i - 1, k, A));
            }
        }
    }
    ll ans = *min_element(dp.at(L).begin(), dp.at(L).end());
    cout << ans << endl;
    return 0;
}