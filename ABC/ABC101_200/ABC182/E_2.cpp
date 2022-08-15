#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

int main(){
    ll H, W, N , M;
    cin >> H >> W >> N >> M;
    vector<pair<ll, ll>> AB(N);
    vector<pair<ll, ll>> CD(M);
    for(auto &ab : AB) {
        cin >> ab.first >> ab.second;
        ab.first--;
        ab.second--;
    }
    for(auto &cd : CD) {
        cin >> cd.first >> cd.second;
        cd.first--;
        cd.second--;
    }

    vector<vector<ll>> grid(H, vector<ll>(W, 0));
    for(const auto &ab : AB) {
        grid.at(ab.first).at(ab.second) = 1;
    }
    for(const auto &cd : CD) {
        grid.at(cd.first).at(cd.second) = 2;
    }

    vector<vector<bool>> lights(H, vector<bool>(W, false));

    bool flag = false;

    FOR(i, 0, H - 1) {
        FOR(j, 0, W - 1) {
            if(grid.at(i).at(j) == 1) {
                flag = true;
            }
            if(grid.at(i).at(j) == 2) {
                flag = false;
            }
            if(flag) {
                lights.at(i).at(j) = true;
            }
        }
        flag = false;
    }

    FOR(i, 0, H - 1) {
        FORD(j, W - 1, 0) {
            if(grid.at(i).at(j) == 1) {
                flag = true;
            }
            if(grid.at(i).at(j) == 2) {
                flag = false;
            }
            if(flag) {
                lights.at(i).at(j) = true;
            }
        }
        flag = false;
    }

    FOR(j, 0, W - 1) {
        FOR(i, 0, H - 1) {
            if(grid.at(i).at(j) == 1) {
                flag = true;
            }
            if(grid.at(i).at(j) == 2) {
                flag = false;
            }
            if(flag) {
                lights.at(i).at(j) = true;
            }
        }
        flag = false;
    }

    FOR(j, 0, W - 1) {
        FORD(i, H - 1, 0) {
            if(grid.at(i).at(j) == 1) {
                flag = true;
            }
            if(grid.at(i).at(j) == 2) {
                flag = false;
            }
            if(flag) {
                lights.at(i).at(j) = true;
            }
        }
        flag = false;
    }

    ll ans = 0;
    FOR(i, 0, H - 1) {
        FOR(j, 0, W - 1) {
            if(lights.at(i).at(j)) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}