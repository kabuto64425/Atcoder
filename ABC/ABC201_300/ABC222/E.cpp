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

using Graph = vector<vector<pair<ll, ll>>>;

bool dfs(ll v, ll pre, ll goal, const Graph &G, vector<ll> &cnt) {
    if(v == goal) {
        return true;
    }
    for(pair<ll, ll> elm : G.at(v)) {
        if(elm.first == pre) {
            continue;
        }
        bool res = dfs(elm.first, v, goal, G, cnt);
        if(res) {
            cnt.at(elm.second)++;
            return true;
        }
    }
    return false;
}

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(M);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> U(N - 1), V(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> U.at(i) >> V.at(i);
        U.at(i)--;
        V.at(i)--;
    }
    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G[U.at(i)].push_back({V.at(i), i});
        G[V.at(i)].push_back({U.at(i), i});
    }
    vector<ll> cnt(N - 1);
    for(ll i = 0; i < M - 1; i++) {
        dfs(A.at(i) - 1, -1, A.at(i + 1) - 1, G, cnt);
    }
    // メモリ圧縮のため、2行の配列
    vector<vector<mint>> dp(2, vector<mint>(220000));
    ll BASE = 110000;
    dp.at(0).at(BASE) = 1;
    for(ll i = 1; i <= N - 1; i++) {
        // メモリ圧縮のため、次に使う配列を計算
        ll next = i % 2;
        ll pre = 1 - next;
        for(ll j = 0; j < 220000; j++) {
            dp.at(next).at(j) = 0;
        }
        for(ll j = 0; j < 220000; j++) {
            if(j - cnt.at(i - 1) >= 0) {
                dp.at(next).at(j) += dp.at(pre).at(j - cnt.at(i - 1));
            }
            if(j + cnt.at(i - 1) < 220000) {
                dp.at(next).at(j) += dp.at(pre).at(j + cnt.at(i - 1));
            }
        }
    }
    cout << dp.at((N + 1) % 2).at(BASE + K).val() << endl;
    return 0;
}