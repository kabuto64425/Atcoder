#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    vector<vector<bool>> dp(220000, vector<bool>(2, false));
    dp.at(0).at(0) = true;
    dp.at(0).at(1) = true;
    for(ll i = 0; i < N - 1; i++) {
        if(abs(A.at(i + 1) - A.at(i)) <= K) {
            dp.at(i + 1).at(0) = dp.at(i + 1).at(0) | dp.at(i).at(0);
        }
        if(abs(A.at(i + 1) - B.at(i)) <= K) {
            dp.at(i + 1).at(0) = dp.at(i + 1).at(0) | dp.at(i).at(1);
        }
        if(abs(B.at(i + 1) - A.at(i)) <= K) {
            dp.at(i + 1).at(1) = dp.at(i + 1).at(1) | dp.at(i).at(0);
        }
        if(abs(B.at(i + 1) - B.at(i)) <= K) {
            dp.at(i + 1).at(1) = dp.at(i + 1).at(1) | dp.at(i).at(1);
        }
    }
    if(dp.at(N - 1).at(0) || dp.at(N - 1).at(1)) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}