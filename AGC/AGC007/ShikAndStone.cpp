#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll H, W;

bool dfs(const vector<vector<ll>> &grid, ll i, ll j) {
    if(i == (H - 1) and j == (W - 1)) {
        vector<vector<ll>> gridCopy = grid;
        gridCopy[i][j] = 1;
        return all_of(gridCopy.begin(), gridCopy.end(), [](vector<ll> row) {
            return all_of(row.begin(), row.end(), [](ll x) {
                return x != 0;
            });
        });
    }
    if(i == H) {
        return false;
    }
    if(j == W) {
        return false;
    }
    if(grid[i][j] == -1) {
        return false;
    }
    vector<vector<ll>> gridCopy = grid;
    gridCopy[i][j] = 1;
    return (dfs(gridCopy, i + 1, j) or dfs(gridCopy, i, j + 1));
}

int main(){
    cin >> H >> W;
    vector<string> A(H);
    for(string &a : A) {
        cin >> a;
    }
    vector<vector<ll>> grid(H, vector<ll>(W, -1));
    REP(i, H) {
        REP(j, W) {
            if(A[i][j] == '#') {
                grid[i][j] = 0;
            }
        }
    }

    if(dfs(grid, 0, 0)) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}

