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
    string S;
    cin >> S;
    vector<pair<ll, char>> vec;
    char pre = S.at(0);
    ll con = 1;
    for(ll i = 1; i < N; i++) {
        if(S.at(i) != pre) {
            vec.push_back({con, pre});
            pre = S.at(i);
            con = 1;
        } else {
            con++;
        }
    }
    vec.push_back({con, pre});
    
    ll res = 0;
    ll right = 0;
    ll current = 0;
    ll count = 0;
    ll M = vec.size();
    for (ll left = 0; left < M; left++) {
        while (right < M && (count + ((vec.at(right).second == '0')? 1 : 0)) <= K) {
            /* 実際に right を 1 進める */
            // ex: sum += A[right];
            current += vec.at(right).first;
            if(vec.at(right).second == '0') {
                count++;
            }
            right++;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        res = max(res, current);

        /* left をインクリメントする準備 */
        if (right == left) right++;
        else {
            if(vec.at(left).second == '0') {
                count--;
            }
            current -= vec.at(left).first;
        }
    }
    cout << res << endl;
    return 0;
}