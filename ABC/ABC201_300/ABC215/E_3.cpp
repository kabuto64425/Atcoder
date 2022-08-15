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
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll getContestId(char c) {
    return (ll)(c - 'A');
}

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(1200, vector<mint>(11, 0)));

    dp.at(1).at((1 << getContestId(S.at(0)))).at(getContestId(S.at(0))) = 1;
    for(ll i = 1; i < N; i++) {
        ll contestId = getContestId(S.at(i));
        // コンテストに参加
        // 既に参加経験あり
        for(ll bit = 0; bit < (1 << 10); bit++) {
            // 前回と同じコンテストを受ける
            dp.at(i + 1).at(bit).at(contestId) += dp.at(i).at(bit).at(contestId);
            // 前回と異なるコンテストを受ける
            // 既に参加済み
            if((bit & (1 << contestId))) {
                continue;
            }
            for(ll j = 0; j < 10; j++) {
                dp.at(i + 1).at(bit | (1 << contestId)).at(contestId) += dp.at(i).at(bit).at(j);
            }
        }
        // 初参加
        dp.at(i + 1).at((1 << contestId)).at(contestId) += 1;
        // コンテストに不参加
        for(ll bit = 0; bit < (1 << 10); bit++) {
            for(ll j = 0; j < 10; j++) {
                dp.at(i + 1).at(bit).at(j) += dp.at(i).at(bit).at(j);
            }
        }
    }
    mint ans = 0;
    for(ll bit = 0; bit < (1 << 10); bit++) {
        for(ll j = 0; j < 10; j++) {
            ans += dp.at(N).at(bit).at(j);
        }
    }
    cout << ans.val() << endl;
    return 0;
}