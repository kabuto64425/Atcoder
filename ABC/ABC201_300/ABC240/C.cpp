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
    ll N, X;
    cin >> N >> X;
    vector<ll> a(N), b(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i) >> b.at(i);
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(11000, false));
    dp.at(0).at(0) = true;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < 10000; j++) {
            dp.at(i + 1).at(j + a.at(i)) = dp.at(i + 1).at(j + a.at(i)) | dp.at(i).at(j);
            dp.at(i + 1).at(j + b.at(i)) = dp.at(i + 1).at(j + b.at(i)) | dp.at(i).at(j);
        }
    }
    if(dp.at(N).at(X)) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}