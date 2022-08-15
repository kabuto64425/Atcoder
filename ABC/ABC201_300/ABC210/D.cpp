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

ll solver(ll &H, ll &W, ll &C, vector<vector<ll>> &A) {
    vector<vector<ll>> dp(H, vector<ll>(W, INF));
    vector<vector<ll>> dp2(H, vector<ll>(W, INF));
    dp2.at(0).at(0) = A.at(0).at(0);
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(i == 0 and j == 0) {
                continue;
            }
            if(i >= 1) {
                dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i - 1).at(j));
                dp.at(i).at(j) = min(dp.at(i).at(j), A.at(i).at(j) + dp2.at(i - 1).at(j) + C);
            }
            if(j >= 1) {
                dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(j - 1));
                dp.at(i).at(j) = min(dp.at(i).at(j), A.at(i).at(j) + dp2.at(i).at(j - 1) + C);
            }
            if(i >= 1) {
                dp2.at(i).at(j) = min(dp2.at(i).at(j), dp2.at(i - 1).at(j) + C);
            }
            if(j >= 1) {
                dp2.at(i).at(j) = min(dp2.at(i).at(j), dp2.at(i).at(j - 1) + C);
            }
            dp2.at(i).at(j) = min(dp2.at(i).at(j), A.at(i).at(j));
        }
    }

    vector<vector<ll>> dp3(H, vector<ll>(W, INF));
    vector<vector<ll>> dp4(H, vector<ll>(W, INF));
    dp4.at(0).at(W - 1) = A.at(0).at(W - 1);
    for(ll i = 0; i < H; i++) {
        for(ll j = W - 1; j >= 0; j--) {
            if(i == 0 and j == W - 1) {
                continue;
            }
            if(i >= 1) {
                dp3.at(i).at(j) = min(dp3.at(i).at(j), dp3.at(i - 1).at(j));
                dp3.at(i).at(j) = min(dp3.at(i).at(j), A.at(i).at(j) + dp4.at(i - 1).at(j) + C);
            }
            if(j <= W - 2) {
                dp3.at(i).at(j) = min(dp3.at(i).at(j), dp3.at(i).at(j + 1));
                dp3.at(i).at(j) = min(dp3.at(i).at(j), A.at(i).at(j) + dp4.at(i).at(j + 1) + C);
            }
            if(i >= 1) {
                dp4.at(i).at(j) = min(dp4.at(i).at(j), dp4.at(i - 1).at(j) + C);
            }
            if(j <= W - 2) {
                dp4.at(i).at(j) = min(dp4.at(i).at(j), dp4.at(i).at(j + 1) + C);
            }
            dp4.at(i).at(j) = min(dp4.at(i).at(j), A.at(i).at(j));
        }
    }

    return min(dp.at(H - 1).at(W - 1), dp3.at(H - 1).at(0));
}

ll solver2(ll &H, ll &W, ll &C, vector<vector<ll>> &A) {
    ll ans = INF;
    for(ll h1 = 0; h1 < H; h1++) {
        for(ll w1 = 0; w1 < W; w1++) {
            for(ll h2 = 0; h2 < H; h2++) {
                for(ll w2 = 0; w2 < W; w2++) {
                    if(h1 == h2 and w1 == w2) {
                        continue;
                    }
                    ans = min(ans, A.at(h1).at(w1) + A.at(h2).at(w2) + C * (abs(h1 - h2) +abs(w1 - w2)));
                }
            }
        }
    }
    return ans;
}

int main(){
    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            cin >> A.at(i).at(j);
        }
    }

    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    while(true) {
        uniform_int_distribution<ll> dist_HW(2, 2), dist_C(1, 10), dist_A(1, 10);
        ll H = dist_HW(rnd);
        ll W = dist_HW(rnd);
        ll C = dist_C(rnd);
        vector<vector<ll>> A(H, vector<ll>(W));
        for(ll i = 0; i < H; i++) {
            for(ll j = 0; j < W; j++) {
                A.at(i).at(j) = dist_A(rnd);
            }
        }
        ll ans1 = solver(H, W, C, A);
        ll ans2 = solver2(H, W, C, A);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << H << " " << W << " " << C << endl;
            for(ll i = 0; i < H; i++) {
                for(ll j=0; j < W; j++) cout << A[i][j] << " \n"[j==W-1];
            }
            cout << "ans1: " << ans1 << endl;
            cout << "ans2: " << ans2 << endl;
            break;
        } else {
            cout <<"OK" << endl;
        }
    }*/

    cout << solver(H, W, C, A) << endl;
    //cout << solver2(H, W, C, A) << endl;
    return 0;
}