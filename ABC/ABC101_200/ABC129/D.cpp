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

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(ll i = 0; i < H; i++) {
        cin >> S.at(i);
    }
    vector<vector<ll>> v1(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        ll con = 0;
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(j) == '#') {
                con = 0;
                v1.at(i).at(j) = 0;
            } else {
                con++;
                v1.at(i).at(j) = con;
            }
        }
    }
    vector<vector<ll>> v2(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        ll con = 0;
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(W - j - 1) == '#') {
                con = 0;
                v2.at(i).at(W - j - 1) = 0;
            } else {
                con++;
                v2.at(i).at(W - j - 1) = con;
            }
        }
    }
    vector<vector<ll>> v3(H, vector<ll>(W));
    for(ll j = 0; j < W; j++) {
        ll con = 0;
        for(ll i = 0; i < H; i++) {
            if(S.at(i).at(j) == '#') {
                con = 0;
                v3.at(i).at(j) = 0;
            } else {
                con++;
                v3.at(i).at(j) = con;
            }
        }
    }
    vector<vector<ll>> v4(H, vector<ll>(W));
    for(ll j = 0; j < W; j++) {
        ll con = 0;
        for(ll i = 0; i < H; i++) {
            if(S.at(H - i - 1).at(j) == '#') {
                con = 0;
                v4.at(H - i - 1).at(j) = 0;
            } else {
                con++;
                v4.at(H - i - 1).at(j) = con;
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
             if(S.at(i).at(j) == '#') {
                 continue;
             }
             ans = max(ans, v1.at(i).at(j) + v2.at(i).at(j) + v3.at(i).at(j) + v4.at(i).at(j) - 3);
        }
    }
    cout << ans << endl;
    return 0;
}