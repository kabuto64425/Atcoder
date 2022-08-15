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
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> B(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            cin >> A.at(i).at(j);
        }
    }
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            cin >> B.at(i).at(j);
        }
    }
    vector<vector<ll>> C(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            C.at(i).at(j) = B.at(i).at(j) - A.at(i).at(j);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < H - 1; i++) {
        for(ll j = 0; j < W - 1; j++) {
            ll d = C.at(i).at(j);
            C.at(i).at(j) -= d;
            C.at(i + 1).at(j) -= d;
            C.at(i).at(j + 1) -= d;
            C.at(i + 1).at(j + 1) -= d;
            ans += abs(d);
        }
    }
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(C.at(i).at(j) != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
    return 0;
}