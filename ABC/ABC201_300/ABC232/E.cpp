#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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

mint solver(ll H, ll W, ll K, ll x1, ll y1, ll x2, ll y2) {
    vector<vector<mint>> dp(K + 1, vector<mint>(4));
    if(x1 != x2 and y1 != y2) {
        dp.at(0).at(0) = 1;
    } else if(x1 == x2 and y1 != y2) {
        dp.at(0).at(1) = 1;
    } else if(x1 != x2 and y1 == y2) {
        dp.at(0).at(2) = 1;
    } else {
        dp.at(0).at(3) = 1;
    }
    for(ll i = 1; i <= K; i++) {
        dp.at(i).at(0) = (H - 2 + W - 2) * dp.at(i - 1).at(0) + (H - 1) * dp.at(i - 1).at(1) + (W - 1) * dp.at(i - 1).at(2);
        dp.at(i).at(1) = dp.at(i - 1).at(0) + (W - 2) * dp.at(i - 1).at(1) + (W - 1) * dp.at(i - 1).at(3);
        dp.at(i).at(2) = dp.at(i - 1).at(0) + (H - 2) * dp.at(i - 1).at(2) + (H - 1) * dp.at(i - 1).at(3);
        dp.at(i).at(3) = dp.at(i - 1).at(1) + dp.at(i - 1).at(2);
    }
    return dp.at(K).at(3);
}

mint solver2(ll H, ll W, ll K, ll x1, ll y1, ll x2, ll y2) {
    vector<vector<vector<mint>>> dp(K + 1, vector<vector<mint>>(H, vector<mint>(W, 0)));
    dp.at(0).at(x1 - 1).at(y1 - 1) = 1;
    for(ll k = 1; k <= K; k++) {
        vector<vector<mint>> temp1 = dp.at(k - 1);
        vector<vector<mint>> temp2 = dp.at(k - 1);
        vector<vector<mint>> temp3 = dp.at(k - 1);
        vector<vector<mint>> temp4 = dp.at(k - 1);
        for(ll i = 0; i < H; i++) for(ll j = 1; j < W; j++) {
            temp1.at(i).at(j) += temp1.at(i).at(j - 1);
        }
        for(ll i = 0; i < H; i++) for(ll j = W - 2; j >= 0; j--) {
            temp2.at(i).at(j) += temp2.at(i).at(j + 1);
        }
        for(ll j = 0; j < W; j++) for(ll i = 1; i < H; i++) {
            temp3.at(i).at(j) += temp3.at(i - 1).at(j);
        }
        for(ll j = 0; j < W; j++) for(ll i = H - 2; i >= 0; i--) {
            temp4.at(i).at(j) += temp4.at(i + 1).at(j);
        }
        for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) {
            dp.at(k).at(i).at(j) = temp1.at(i).at(j) + temp2.at(i).at(j) + temp3.at(i).at(j) + temp4.at(i).at(j) - 4 * dp.at(k - 1).at(i).at(j);
        }
    }
    return dp.at(K).at(x2 - 1).at(y2 - 1);
}

int main(){
    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());*/

    /*while(true) {
        uniform_int_distribution<ll> dist_HW(2, 10), dist_K(1, 3);
        ll H = dist_HW(rnd);
        ll W = dist_HW(rnd);
        ll K = dist_K(rnd);
        uniform_int_distribution<ll> dist_x(1, H), dist_y(1, W);
        ll x1 = dist_x(rnd);
        ll y1 = dist_y(rnd);
        ll x2 = dist_x(rnd);
        ll y2 = dist_y(rnd);
        mint ans1 = solver(H, W, K, x1, y1, x2, y2);
        mint ans2 = solver2(H, W, K, x1, y1, x2, y2);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << H << " " << W << " " << K << endl;
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
    }*/
    
    cout << solver(H, W, K, x1, y1, x2, y2).val() << endl;
    /*cout << solver2(H, W, K, x1, y1, x2, y2).val() << endl;*/
    return 0;
}