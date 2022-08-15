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
    ll N;
    cin >> N;
    vector<ll> A(2 * N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<vector<ll>> dp(401, vector<ll>(401));
    for (ll i = 1; i <= 2 * N; i++) {
        for (int j = i; j <= 2 * N; j++) {
            dp.at(i).at(j) = INF;
        }
        if(i < 2 * N) {
            dp.at(i).at(i + 1) = abs(A.at(i - 1) - A.at(i));
        } 
    }

    // Step #3. DP
    for(ll sectionLength = 4; sectionLength <= 2 * N; sectionLength += 2) {
        for(ll i = 1; i <= 2 * N - sectionLength + 1; i++) {
            ll cl = i;
            ll cr = i + sectionLength - 1;
            for(ll k = i; k <= cr - 1; k++) {
                dp.at(cl).at(cr) = min(dp.at(cl).at(cr), dp.at(cl).at(k) + dp.at(k + 1).at(cr));
            }
            dp.at(cl).at(cr) = min(dp.at(cl).at(cr), dp.at(cl + 1).at(cr - 1) + abs(A.at(cl - 1) - A.at(cr - 1)));
        }
    }
    cout << dp.at(1).at(N * 2) << endl;
    return 0;
}