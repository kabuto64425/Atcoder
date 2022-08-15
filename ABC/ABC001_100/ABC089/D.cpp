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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W, D;
    cin >> H >> W >> D;
    vector<vector<ll>> A(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) {
        cin >> A.at(i).at(j);
    }
    ll Q;
    cin >> Q;
    vector<ll> L(Q), R(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> L.at(i) >> R.at(i);
    }
    vector<vector<ll>> v(D + 1);
    for(ll i = 1; i <= D; i++) {
        v.at(i).push_back(0);
    }
    vector<pair<ll, ll>> pos(H * W + 1);
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) {
        pos.at(A.at(i).at(j)) = {i + 1, j + 1};
    }
    for(ll i = 1; i <= D; i++) {
        for(ll j = i + D; j <= H * W; j += D) {
            pair<ll, ll> currentpos = pos.at(j);
            pair<ll, ll> prepos = pos.at(j - D);
            v.at(i).push_back(abs(currentpos.first - prepos.first) + abs(currentpos.second - prepos.second));
        }
        for(ll j = 1; j < (ll)v.at(i).size(); j++) {
            v.at(i).at(j) += v.at(i).at(j - 1);
        }
    }
    for(ll i = 0; i < Q; i++) {
        ll l = L.at(i);
        ll r = R.at(i);
        ll index = (l - 1) % D + 1;
        ll start = (l + (D - 1)) / D - 1;
        ll goal = (r + (D - 1)) / D - 1;
        if(start < 0) {
            cout << v.at(index).at(goal) << endl;
        } else {
            cout << v.at(index).at(goal) - v.at(index).at(start) << endl;
        }
    }
    return 0;
}