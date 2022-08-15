#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S.at(i);
    }
    vector<vector<ll>> grid(H, vector<ll>(W, 0));
    ll K = 0;
    REP(i, H) {
        REP(j, W) {
            if(S.at(i).at(j) == '#') {
                grid.at(i).at(j) = 1;
            } else {
                K++;
            }
        }
    }

    vector<vector<ll>> lights(H, vector<ll>(W, 0));
    ll count = 0;
    FOR(i, 0, H - 1) {
        FOR(j, 0, W - 1) {
            if(grid.at(i).at(j) == 1) {
                count = 0;
            } else {
                count++;
                lights.at(i).at(j) += count;
            }
        }
        count = 0;
    }

    FOR(i, 0, H - 1) {
        FORD(j, W - 1, 0) {
            if(grid.at(i).at(j) == 1) {
                count = 0;
            } else {
                count++;
                lights.at(i).at(j) += count;
            }
        }
        count = 0;
    }

    FOR(i, 0, W - 1) {
        FOR(j, 0, H - 1) {
            if(grid.at(j).at(i) == 1) {
                count = 0;
            } else {
                count++;
                lights.at(j).at(i) += count;
            }
        }
        count = 0;
    }

    FOR(i, 0, W - 1) {
        FORD(j, H - 1, 0) {
            if(grid.at(j).at(i) == 1) {
                count = 0;
            } else {
                count++;
                lights.at(j).at(i) += count;
            }
        }
        count = 0;
    }

    ll ans = 0;

    REP(i, H) {
        REP(j, W) {
            if(grid.at(i).at(j) == 1) {
                continue;
            }
            ans += (mod_pow(2, K, MOD) - mod_pow(2,  K - (lights.at(i).at(j) - 3), MOD) + MOD) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}