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
/*
  このままではコンパイルエラーが出ます。
  実装に合わせて適宜修正すること
*/
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
    ll res = 0;
    ll sum = accumulate(B.begin(), B.end(), 0LL);
    ll bCount = M;
    for (ll aCount = 0; aCount <= N; aCount++) {
        while (bCount >= 1 && sum > K) {
            /* 実際に right を 1 進める */
            sum -= B.at(bCount - 1);
            bCount--;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        if(sum <= K) {
            res = max(res, aCount + bCount);
        }

        /* left をインクリメントする準備 */
        if(aCount <= N - 1) {
            sum += A.at(aCount);
        }
    }
    cout << res << endl;
    return 0;
}