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
/*
  このままではコンパイルエラーが出ます。
  実装に合わせて適宜修正すること
*/
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll res = 0;
    ll right = 1;
    for (ll left = 0; left < N; left++) {
        while (right < N && (right <= left || A.at(right) > A.at(right - 1))) {
            right++;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        res += (right - left);

        /* left をインクリメントする準備 */
        if (right == left) right++;
    }
    cout << res << endl;
    return 0;
}