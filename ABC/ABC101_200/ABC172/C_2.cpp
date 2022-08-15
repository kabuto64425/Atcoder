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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    vector<ll> B(M);
    for(ll &a : A) {
        cin >> a;
    }
    for(ll &b : B) {
        cin >> b;
    }
    vector<ll> cSumB(M + 1, 0);
    for(ll i = 1; i <= M; i++) {
        cSumB.at(i) = cSumB.at(i - 1) + B.at(i - 1);
    }

    ll ans = 0;
    
    ll sumA = 0;
    for(ll aCount = 0; aCount <= N; aCount++) {
        if(K - sumA < 0) {
            break;
        }
        ll index = upper_bound(cSumB.begin(), cSumB.end(), K - sumA) - cSumB.begin();
        ll bCount = index - 1;
        ans = max(ans, aCount + bCount);
        if(aCount <= N - 1) {
            sumA += A.at(aCount);
        }
    }

    cout << ans << endl;

    return 0;
}