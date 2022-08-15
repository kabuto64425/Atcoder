#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

bool hantei(const ll W, const vector<vector<bool>> &used, ll sx, ll sy) {
    ll dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
    ll dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    for (ll i = 0; i < 8; i++) {
        ll tx = sx + dx[i];
        ll ty = sy + dy[i];
        if (tx < 0 || ty < 0 || ty >= W) continue;
        if (used[tx][ty] == true) return false;
    }
    return true;
}

void dfs(const ll W, ll pos, ll dep, string str, vector<ll> &cnt,
        vector<map<string, pair<int, bool>>> &Map, vector<vector<string>> &state, vector<vector<bool>> &used) {
    ll sx = pos / W;
    ll sy = pos % W;
    if (dep == W + 1) {
        ll idx = cnt[sy];
        bool flag = hantei(W, used, sx, sy);
        state[sy][idx] = str;
        Map[sy][str] = make_pair(idx, flag);
        cnt[sy] += 1;
        return;
    }
    dfs(W, pos + 1, dep + 1, str + "0", cnt, Map, state, used);
    if (hantei(W, used, sx, sy) == true) {
        used[sx][sy] = true;
        dfs(W, pos + 1, dep + 1, str + "1", cnt, Map, state, used);
        used[sx][sy] = false;
    }
}

int main(){
    // Step #1. Input
    ll H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(string &c : C) {
        cin >> c;
    }

    vector<ll> cnt(25);
    vector<map<string, pair<int, bool>>> Map(25);
    vector<vector<string>> state(25, vector<string>(1 << 18));
    vector<vector<bool>> used(25, vector<bool>(25));

    vector<vector<ll>> nex0(25, vector<ll>(1 << 18));
    vector<vector<ll>> nex1(25, vector<ll>(1 << 18));

    // Step #2. Initialize
    for (ll i = 0; i < W; i++) {
        dfs(W, i, 0, "", cnt, Map, state, used);
    }

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            string t = state[i][j];
            string t0 = t.substr(1, t.size() - 1) + "0";
            string t1 = t.substr(1, t.size() - 1) + "1";
            nex0[i][j] = Map[(i + 1) % W][t0].first;
            if (Map[i][t].second == true) {
                nex1[i][j] = Map[(i + 1) % W][t1].first;
            } else {
                nex1[i][j] = -1;
            }
        }
    }

    // Step #3. DP
    vector<vector<vector<mint>>> dp(25, vector<vector<mint>>(25, vector<mint>(1 << 18)));
    dp.at(0).at(0).at(0) = 1;
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            ll n1 = i;
            ll n2 = j + 1;
            if (n2 == W) {
                n1 += 1; n2 = 0;
            }
            
            for (int k = 0; k < cnt[j]; k++) {
                if (dp[i][j][k] == 0) continue;
                dp[n1][n2][nex0[j][k]] += dp[i][j][k];
                if (nex1[j][k] != -1 && C[i][j] == '.') {
                    dp[n1][n2][nex1[j][k]] += dp[i][j][k];
                }
            }
        }
    }

    // Step #3. Get Answer
    mint ans = 0;
    for (int i = 0; i < cnt[0]; i++) {
        ans += dp[H][0][i];
	}
    cout << ans.val() << endl;
    return 0;
}