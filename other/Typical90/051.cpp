#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(6));
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i).at(0) >> A.at(i).at(1) >> A.at(i).at(2) >> A.at(i).at(3) >> A.at(i).at(4) >> A.at(i).at(5);
    }
    mint ans = 1;
    for(ll i = 0; i < N; i++) {
        ans *= (A.at(i).at(0) + A.at(i).at(1) + A.at(i).at(2) + A.at(i).at(3) + A.at(i).at(4) + A.at(i).at(5));
    }
    cout << ans.val() << endl;
    return 0;
}