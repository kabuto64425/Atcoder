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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(string &s : S) {
        cin >> s;
    }
    vector<vector<ll>> grid(H + 2, vector<ll>(W + 2, 0));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(j) == '#') {
                grid.at(i + 1).at(j + 1) = 1;
            }
        }
    }

    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {-1, 1},
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
    };
    
    for(ll i = 1; i <= H; i++) {
        for(ll j = 1; j <= W; j++) {
            if(grid.at(i).at(j) == 1) {
                cout << '#';
                continue;
            }
            ll count = 0;
            for (pair<ll, ll> d : ds) {
                if(grid.at(i + d.first).at(j + d.second) == 1) {
                    count++;
                }
            }
            cout << count;
        }
        cout << endl;
    }
    return 0;
}