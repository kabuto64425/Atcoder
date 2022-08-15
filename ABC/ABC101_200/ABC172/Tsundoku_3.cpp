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
    vector<ll> A(N);
    vector<ll> sumA(N + 1);
    vector<ll> B(M);
    vector<ll> sumB(M + 1);
    for(ll &a: A) {
        cin >> a;
    }
    for(ll &b: B) {
        cin >> b;
    }
    for(ll i = 1; i <= N; i++) {
        sumA[i] = sumA[i - 1] + A[i - 1];
    }
    for(ll i = 1; i <= M; i++) {
        sumB[i] = sumB[i - 1] + B[i - 1];
    }
    ll ans = 0;
    for(ll a = 0; a <= N; a++) {
        ll b = (upper_bound(sumB.begin(), sumB.end(), K - sumA[a]) - sumB.begin()) - 1;
        if(sumA[a] + sumB[max(0LL, b)] <= K) {
            ans = max(ans, a + b);
        }
    }
    cout << ans << endl;
    return 0;
}