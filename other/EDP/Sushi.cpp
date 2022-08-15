#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
 
const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    vector<vector<vector<long double>>> dp(N + 1, vector<vector<long double>>(N + 1, vector<long double>(N + 1, 0)));
    for(ll i = 0; i <= N; i++) {
        for(ll j = 0; j <= N; j++) {
            for(ll k = 0; k <= N; k++) {
                if(i == 0 and j == 0 and k == 0) {
                    dp.at(k).at(j).at(i) = 0;
                    continue;
                }
                if(i + j + k > N) {
                    continue;
                }
                if(i > 0) {
                    dp.at(k).at(j).at(i) += (dp.at(k).at(j + 1).at(i - 1) + N / (long double)(i + j + k)) * (i) / (long double)(i + j + k);
                }
                if(j > 0) {
                    dp.at(k).at(j).at(i) += (dp.at(k + 1).at(j - 1).at(i) + N / (long double)(i + j + k)) * (j) / (long double)(i + j + k);
                }
                if(k > 0) {
                    dp.at(k).at(j).at(i) += (dp.at(k - 1).at(j).at(i) + N / (long double)(i + j + k)) * (k) / (long double)(i + j + k);
                }
            }
        }
    }
    ll oneCount = count(a.begin(), a.end(), 1);
    ll twoCount = count(a.begin(), a.end(), 2);
    ll threeCount = count(a.begin(), a.end(), 3);
    cout << fixed << setprecision(20) << dp.at(oneCount).at(twoCount).at(threeCount) << endl;
    return 0;
}
