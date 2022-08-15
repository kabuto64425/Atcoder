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
    for(ll i = 100; i >= 0; i--) {
        for(ll j = 100; j >= 0; j--) {
            for(ll k = 100; k >= 0; k--) {
                if(i == 100 or j == 100 or k == 100) {
                    continue;
                }
                dp.at(i).at(j).at(k) += (dp.at(i + 1).at(j).at(k) + 1) * (i) / (long double)(i + j + k);
                dp.at(i).at(j).at(k) += (dp.at(i).at(j + 1).at(k) + 1) * (j) / (long double)(i + j + k);
                dp.at(i).at(j).at(k) += (dp.at(i).at(j).at(k + 1) + 1) * (k) / (long double)(i + j + k);
            }
        }
    }
    cout << fixed << setprecision(20) << dp.at(A).at(B).at(C) << endl;
    return 0;
}