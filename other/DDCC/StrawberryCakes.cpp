#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> s(H);
    for(string &elm : s) {
        cin >> elm;
    }
    vector<vector<ll>> ans(H, vector<ll>(W, 0));
    ll count = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(s.at(i).at(j) == '#') {
                count++;
                ans.at(i).at(j) = count;
            }
        }
    }

    for(ll j = 0; j < W; j++) {
        for(ll i = 0; i < H; i++) {
            if(i > 0 and ans.at(i).at(j) == 0) {
                ans.at(i).at(j) = ans.at(i - 1).at(j);
            }
        }
    }

    for(ll j = 0; j < W; j++) {
        for(ll i = H - 1; i >= 0; i--) {
            if(i <= H - 2 and ans.at(i).at(j) == 0) {
                ans.at(i).at(j) = ans.at(i + 1).at(j);
            }
        }
    }

    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(j > 0 and ans.at(i).at(j) == 0) {
                ans.at(i).at(j) = ans.at(i).at(j - 1);
            }
        }
    }

    for(ll i = 0; i < H; i++) {
        for(ll j = W - 1; j >= 0; j--) {
            if(j <= W - 2 and ans.at(i).at(j) == 0) {
                ans.at(i).at(j) = ans.at(i).at(j + 1);
            }
        }
    }

    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}