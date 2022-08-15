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

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(string &s : S) {
        cin >> s;
    }
    vector<vector<ll>> vec(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        ll con = 0;
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(j) == '.') {
                con++;
            } else {
                con = 0;
            }
            vec.at(i).at(j) += con;
        }
    }
    for(ll i = 0; i < H; i++) {
        ll con = 0;
        for(ll j = W - 1; j >= 0; j--) {
            if(S.at(i).at(j) == '.') {
                con++;
            } else {
                con = 0;
            }
            vec.at(i).at(j) += con;
        }
    }
    for(ll j = 0; j < W; j++) {
        ll con = 0;
        for(ll i = 0; i < H; i++) {
            if(S.at(i).at(j) == '.') {
                con++;
            } else {
                con = 0;
            }
            vec.at(i).at(j) += con;
        }
    }
    for(ll j = 0; j < W; j++) {
        ll con = 0;
        for(ll i = H - 1; i >= 0; i--) {
            if(S.at(i).at(j) == '.') {
                con++;
            } else {
                con = 0;
            }
            vec.at(i).at(j) += con;
        }
    }
    ll K = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(j) == '.') {
                K++;
            }
        }
    }
    vector<mint> doublePow(K + 1);
    doublePow.at(0) = 1;
    for(ll i = 1; i <= K; i++) {
        doublePow.at(i) = doublePow.at(i - 1) * 2;
    }
    mint ans = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(j) == '#') {
                continue;
            }
            ans += doublePow.at(K);
            ans -= doublePow.at(K - (vec.at(i).at(j) - 3));
        }
    }
    cout << ans.val() << endl;
    return 0;
}