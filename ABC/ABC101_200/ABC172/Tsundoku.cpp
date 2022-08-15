#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N + 1);
    vector<ll> sumA(N + 1);
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        sumA[i] = sumA[i - 1] + A[i];
    }
    
    vector<ll> B(M);
    vector<ll> sumB(M + 1);
    for(ll i = 1; i <= M; i++) {
        cin >> B[i];
        sumB[i] = sumB[i - 1] + B[i];
    }
    ll ans = 0;

    for(ll countA = 0; countA <= N; countA++) {
        ll rest = K - sumA[countA];
        if(rest < 0) {
            continue;
        }
        ll countB = M - (sumB.end() - upper_bound(sumB.begin(), sumB.end(), rest));
        ans = max(ans, countA + countB);
    }

    cout << ans << endl;
    return 0;
}