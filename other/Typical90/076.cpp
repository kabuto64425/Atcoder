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
    ll N;
    cin >> N;
    vector<ll> A(2 * N);
    ll target = 0;
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
        target += A.at(i);
    }
    if(target % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }
    target /= 10;

    for(ll i = N; i < 2 * N; i++) {
        A.at(i) = A.at(i - N);
    }

    ll res = 0;
    ll sum = 0;
    ll right = 0;
    for (ll left = 0; left < 2 * N; left++) {
        while (right < 2 * N && (sum + A[right] <= target)) {
            /* 実際に right を 1 進める */
            sum += A[right];
            right++;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        // ex: res += (right - left);
        if(sum == target) {
            cout << "Yes" << endl;
            return 0;
        }

        /* left をインクリメントする準備 */
        if (right == left) right++;
        else sum -= A[left];
    }
    cout << "No" << endl;
    return 0;
}