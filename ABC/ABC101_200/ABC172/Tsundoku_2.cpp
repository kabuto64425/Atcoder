#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法
/*
  このままではコンパイルエラーが出ます。
  実装に合わせて適宜修正すること
*/
int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    vector<ll> B(M);
    for(ll &a: A) {
        cin >> a;
    }
    for(ll &b: B) {
        cin >> b;
    }
    ll sum = accumulate(B.begin(), B.end(), 0LL);
    ll b = M;
    ll ans = 0;
    for (ll a = 0; a <= N; a++) {
        while (b > 0 && sum > K) {
            /* 実際に right を 1 進める */
            sum -= B[b - 1];
            b--;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        if(sum <= K) {
            ans = max(ans, a + b);
        }

        /* left をインクリメントする準備 */
        if(a < N) {
            sum += A[a];
        }
    }
    cout << ans << endl;
    return 0;
}