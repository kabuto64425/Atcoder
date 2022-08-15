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
    ll A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<long double>>> dp(101, vector<vector<long double>>(101, vector<long double>(101, 0)));
    for(ll a = 100; a >= 0; a--) {
        for(ll b = 100; b >= 0; b--) {
            for(ll c = 100; c >= 0; c--) {
                if(a == 100 or b == 100 or c == 100) {
                    continue;
                }
                dp.at(a).at(b).at(c) += (long double)a * (dp.at(a + 1).at(b).at(c) + 1) / (long double)(a + b + c);
                dp.at(a).at(b).at(c) += (long double)b * (dp.at(a).at(b + 1).at(c) + 1) / (long double)(a + b + c);
                dp.at(a).at(b).at(c) += (long double)c * (dp.at(a).at(b).at(c + 1) + 1) / (long double)(a + b + c);
            }
        }
    }
    cout << fixed << setprecision(20) << dp.at(A).at(B).at(C) << endl;
    return 0;
}