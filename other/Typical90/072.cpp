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

vector<pair<ll, ll>> ds = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

ll dfs(const vector<vector<ll>> &grid, const pair<ll, ll> start, pair<ll, ll> pos, vector<vector<bool>> &seen, ll depth) {
    if(start == pos and seen.at(pos.first).at(pos.second)) {
        return 0;
    }
    seen.at(pos.first).at(pos.second) = true;
    ll H = grid.size();
    ll W = grid.at(0).size();
    ll res = -100000;
    for(pair<ll, ll> d : ds) {
        ll y = pos.first + d.first;
        ll x = pos.second + d.second;
        if(y < 0 or x < 0 or y >= H or x >= W) {
            continue;
        }
        if(grid.at(y).at(x) == 1) {
            continue;
        }
        if(make_pair(y, x) != start and seen.at(y).at(x)) {
            continue;
        }
        res = max(res, dfs(grid, start, {y, x}, seen, depth + 1) + 1);
    }
    seen.at(pos.first).at(pos.second) = false;
    return res;
}

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> c(H);
    for(ll i = 0; i < H; i++) {
        cin >> c.at(i);
    }

    vector<vector<ll>> grid(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(c.at(i).at(j) == '#') {
                grid.at(i).at(j) = 1;
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            vector<vector<bool>> seen(H, vector<bool>(W));
            ans = max(ans, dfs(grid, {i, j}, {i, j}, seen, 0));
        }
    }

    if(ans <= 2) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
    return 0;
}