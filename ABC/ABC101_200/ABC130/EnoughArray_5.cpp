#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    ll res = 0;
    ll sum = 0;
    ll right = 0;
    for (ll left = 0; left < N; left++) {
        while (right < N && (sum < K)) {
            /* 実際に right を 1 進める */
            sum += a[right];
            right++;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        if(sum >= K) {
            res += N - right + 1;
        }

        /* left をインクリメントする準備 */
        if (right == left) right++;
        else sum -= a[left];
    }
    cout << res << endl;
    return 0;
}