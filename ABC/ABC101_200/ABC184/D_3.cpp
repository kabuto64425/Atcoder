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
    ll A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<long double>>> dp(101, vector<vector<long double>>(101, vector<long double>(101, 0)));
    for(ll x = 100; x >= 0; x--) {
        for(ll y = 100; y >= 0; y--) {
            for(ll z = 100; z >= 0; z--) {
                if(x == 100 or y == 100 or z == 100) {
                    dp.at(x).at(y).at(z) = 0;
                    continue;
                }
                dp.at(x).at(y).at(z) += (dp.at(x + 1).at(y).at(z) + 1) * (x) / (long double)(x + y + z);
                dp.at(x).at(y).at(z) += (dp.at(x).at(y + 1).at(z) + 1) * (y) / (long double)(x + y + z);
                dp.at(x).at(y).at(z) += (dp.at(x).at(y).at(z + 1) + 1) * (z) / (long double)(x + y + z);
            }
        }
    }
    cout << fixed << setprecision(20) << dp.at(A).at(B).at(C) << endl;
    return 0;
}