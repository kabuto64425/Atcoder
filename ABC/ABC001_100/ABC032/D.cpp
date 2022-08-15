#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

bool checkCase2(vector<pair<ll, ll>> const &vw) {
    return all_of(vw.begin(), vw.end(), [](pair<ll, ll> x) {
        return x.second <= 1000;
    });
}

ll solveCase1(ll N, ll W, vector<pair<ll, ll>> const &vw) {
    
    return 0;
}

ll solveCase2(ll N, ll W, vector<pair<ll, ll>> const &vw) {
    vector<vector<ll>> dp(N + 1, vector<ll>(200001, 0));
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 200000; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);
            if(j - vw.at(i - 1).second >= 0) {
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j - vw.at(i - 1).second) + vw.at(i - 1).first);
            }
        }
    }
    ll res = 0;
    for(ll i = 0; i <= W; i++) {
        res = max(res, dp.at(N).at(i));
    }
    return res;
}

ll solveCase3(ll N, ll W, vector<pair<ll, ll>> const &vw) {
    vector<vector<ll>> dp(N + 1, vector<ll>(200001, INF));
    dp.at(0).at(0) = 0;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= 200000; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);
            if(j - vw.at(i - 1).first >= 0) {
                dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i - 1).at(j - vw.at(i - 1).first) + vw.at(i - 1).second);
            }
        }
    }
    for(ll i = 200000; i >= 0; i--) {
        if(dp.at(N).at(i) <= W) {
            return i;
            break;
        }
    }
    return 0;
}

int main(){
    ll N, W;
    cin >> N >> W;
    vector<pair<ll, ll>> vw(N);
    for(pair<ll, ll> &elm : vw) {
        cin >> elm.first >> elm.second;
    }
    if(N <= 30) {
        cout << solveCase1(N, W, vw) << endl;
        return 0;
    }
    if(checkCase2(vw)) {
        cout << solveCase2(N, W, vw) << endl;
        return 0;
    }
    cout << solveCase3(N, W, vw) << endl;
    return 0;
}