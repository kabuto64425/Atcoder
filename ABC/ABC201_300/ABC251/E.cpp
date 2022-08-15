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

void chmin(ll &a, ll b) {
    a = min(a, b);
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<vector<ll>> dp(N, vector<ll>(2, INF));
    dp.at(0).at(1) = A.at(0);
    for(ll i = 0; i < N - 1; i++) {
        chmin(dp.at(i + 1).at(1), dp.at(i).at(1) + A.at(i + 1));
        chmin(dp.at(i + 1).at(1), dp.at(i).at(0) + A.at(i + 1));

        chmin(dp.at(i + 1).at(0), dp.at(i).at(1));
    }

    vector<ll> B(N);
    for(ll i = 0; i < N; i++) {
        B.at(i) = A.at((i - 1 + N) % N);
    }

    vector<vector<ll>> dp2(N, vector<ll>(2, INF));
    dp2.at(0).at(1) = B.at(0);
    for(ll i = 0; i < N - 1; i++) {
        chmin(dp2.at(i + 1).at(1), dp2.at(i).at(1) + B.at(i + 1));
        chmin(dp2.at(i + 1).at(1), dp2.at(i).at(0) + B.at(i + 1));

        chmin(dp2.at(i + 1).at(0), dp2.at(i).at(1));
    }
    
    cout << min({dp.at(N - 1).at(0), dp.at(N - 1).at(1), dp2.at(N - 1).at(0), dp2.at(N - 1).at(1)}) << endl;
    return 0;
}