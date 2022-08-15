#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll H, W, N ,M;
    cin >> H >> W >> N >> M;
    vector<vector<ll>> grid(H, vector<ll>(W, 0));
    REP(i, N) {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        grid.at(A).at(B) = 1;
    }
    REP(i, M) {
        ll C, D;
        cin >> C >> D;
        C--;
        D--;
        grid.at(C).at(D) = 2;
    }
    vector<vector<bool>> lights(H, vector<bool>(W, false));

    bool flag = false;

    REP(i, H) {
        REP(j, W) {
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

    REP(i, H) {
        REP(j, W) {
            if(grid.at(i).at(W - j - 1) == 1) {
                flag = true;
            }
            if(grid.at(i).at(W - j - 1) == 2) {
                flag = false;
            }
            if(flag) {
                lights.at(i).at(W - j - 1) = true;
            }
        }
        flag = false;
    }

    REP(i, W) {
        REP(j, H) {
            if(grid.at(j).at(i) == 1) {
                flag = true;
            }
            if(grid.at(j).at(i) == 2) {
                flag = false;
            }
            if(flag) {
                lights.at(j).at(i) = true;
            }
        }
        flag = false;
    }

    REP(i, W) {
        REP(j, H) {
            if(grid.at(H - j - 1).at(i) == 1) {
                flag = true;
            }
            if(grid.at(H - j - 1).at(i) == 2) {
                flag = false;
            }
            if(flag) {
                lights.at(H - j - 1).at(i) = true;
            }
        }
        flag = false;
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if(lights.at(i).at(j)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}