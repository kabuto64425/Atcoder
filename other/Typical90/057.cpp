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

int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> D(N, vector<ll>(M, 0));
    for (ll i = 0; i < N; ++i) {
        ll t, x;
        cin >> t;
        for (ll j = 0; j < t; ++j) {
            cin >> x;
            x--;
            D[i][x] = 1;
        }
    }
    vector<ll> S(M);
    for (ll i = 0; i < M; ++i) {
        cin >> S[i];
    }
    // 行列の掃き出し
    ll pos = 0;
    for (ll i = 0; i < M; ++i) {
        bool found = false;
        // iの場所で初めて1が見つかる行を探す
        // 見つかれば、それをもとにして答えが変わらないように他の行を変換
        for (ll j = pos; j < N; ++j) {
            if (D[j][i] == 1) {
                if (j != pos) {
                    swap(D[j], D[pos]);
                }
                found = true;
                break;
            }
        }
        if (found) {
            // 見つかった場合、他の行でiが1の行があれば、その行に変換をかける
            for (ll j = 0; j < N; ++j) {
                if (j != pos && D[j][i] == 1) {
                    for (ll k = i; k < M; ++k) {
                        D[j][k] ^= D[pos][k];
                    }
                }
            }
            // posの行にしか、iの場所で1がない状態になっているため、
            // S[i]が1の場合は、S[i]に変換をかける
            if (S[i] == 1) {
                for (ll j = i; j < M; ++j) {
                    S[j] ^= D[pos][j];
                }
            }
            ++pos;
        }
    }
    // Sが全て0なら、入力に対して答えが存在することになる。
    if (S == vector<ll>(M, 0)) {
        ll ans = 1;
        for (ll i = pos; i < N; ++i) {
            // Dの行のうち、全てが0の行の分だけ、その行を選ぶ・選ばないを決めることができるため。
            ans = ans * 2 % 998244353;
        }
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}