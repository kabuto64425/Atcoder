#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(10, vector<mint>(1024, 0)));
    for(ll i = 1; i <= N; i++) {
        // c:今回のコンテスト
        ll c = S.at(i - 1) - 'A';
        
        // 今回は参加しないパターン
        for(ll j = 0; j < 10; j++) {
            for(ll bit = 0; bit < 1024; bit++) {
                dp.at(i).at(j).at(bit) += dp.at(i - 1).at(j).at(bit);
            }
        }
        // 今回は参加し、前回参加したときと同じコンテストであるパターン
        for(ll bit = 0; bit < 1024; bit++) {
            dp.at(i).at(c).at(bit) += dp.at(i - 1).at(c).at(bit);
        }
        // 今回は参加し、前回参加したときと異なるコンテストであるパターン
        for(ll j = 0; j < 10; j++) {
            for(ll bit = 0; bit < 1024; bit++) {
                if(bit & (1 << c)) {
                    dp.at(i).at(c).at(bit) += dp.at(i - 1).at(j).at(bit & ~(1 << c));
                }
            }
        }
        
        // 今回のコンテストで初参加するパターン
        dp.at(i).at(c).at((1 << c)) += 1;
    }
    mint ans = 0;
    for(ll i = 0; i < 10; i++) {
        for(ll bit = 1; bit < 1024; bit++) {
            ans += dp.at(N).at(i).at(bit);
        }
    }
    cout << ans.val() << endl;
    return 0;
}