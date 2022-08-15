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
/*
  このままではコンパイルエラーが出ます。
  実装に合わせて適宜修正すること
*/
int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ll res = 0;
    ll sum = 0;
    ll right = 0;
    for (ll left = 0; left < N; left++) {
        while (right < N && sum + A[right] < K) {
            /* 実際に right を 1 進める */
            // ex: sum += A[right];
            sum += A[right];
            right++;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        // ex: res += (right - left);
        res += N - right;

        /* left をインクリメントする準備 */
        if (right == left) right++;
        else sum -= A[left];
    }
    cout << res << endl;
    return 0;
}