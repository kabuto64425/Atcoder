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

int main(){
    ll N;
    cin >> N;
    string S;
    string T;
    cin >> S;
    cin >> T;

    vector<ll> seq1(N), seq3(N);
    for (ll i = 0; i < N; ++i) {
        seq1.at(i) = (S.at(i) == 'R' ? 0 : (S.at(i) == 'G' ? 1 : 2));
        seq3.at(i) = (T.at(i) == 'R' ? 0 : (T.at(i) == 'G' ? 1 : 2));
    }
    ll ans = 0;
    // 3色分
    for (ll i = 0; i < 3; ++i) {
        vector<ll> seq2(N);
        // 色の置換
        // 対象の色以外の2色を入れ替え（対象がRの場合、GをBに、BをGに置き換え）
        // これにより、seq1とseq2との比較だけで条件判定ができる
        for (ll j = 0; j < N; ++j) {
            seq2[j] = (i - seq3[j] + 3) % 3;
        }

        // ローリングハッシュ法で一致判定を行う
        ll power3 = 1, hash1 = 0, hash2 = 0;
        for (ll j = 0; j < N; ++j) {
            hash1 = (hash1 * 3 + seq1[j]) % MOD;
            hash2 = (hash2 + power3 * seq2[N - j - 1]) % MOD;
            if (hash1 == hash2) {
                ans++;
            }
            power3 = power3 * 3 % MOD;
        }
        power3 = 1, hash1 = 0, hash2 = 0;
        for (int j = 0; j < N - 1; ++j) {
            hash1 = (hash1 + power3 * seq1[N - j - 1]) % MOD;
            hash2 = (hash2 * 3 + seq2[j]) % MOD;
            if (hash1 == hash2) {
                ans++;
            }
            power3 = power3 * 3 % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}