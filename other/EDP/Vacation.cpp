#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = LLONG_MAX;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> abc(N, vector<ll>(3));
    for(vector<ll> &elm :abc) {
        cin >> elm.at(0) >> elm.at(1) >> elm.at(2);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(3));
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j < 3; j++) {
            for(ll k = 0; k < 3; k++) {
                if(j == k) {
                    continue;
                }
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(k) + abc.at(i - 1).at(k));
            }
        }
    }
    cout << *max_element(dp.at(N).begin(), dp.at(N).end()) << endl;
    return 0;
}