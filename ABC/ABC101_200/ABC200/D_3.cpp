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

void rec(const vector<vector<long long>> &dp, const vector<ll> &a, int i, int j, deque<ll> &keiro, vector<deque<ll>> &ans) {
    if (i == 0) {
        if (j == 0) {
            ans.push_back(keiro);
        }
        return;
    }

    // 上へ遡る (dp[i-1][j] == 0) だったら無視)
    if (dp[i-1][j]) {
        rec(dp, a, i-1, j, keiro, ans);
    }
    // 左上へ遡る (dp[i-1][j-a[i-1]] == 0 だったら無視)
    ll dist = a.at(i - 1) % 200;
    ll prev = (j - dist + 200) % 200;
    if (dp[i-1][prev]) {
        keiro.push_front(i);
        rec(dp, a, i-1, prev, keiro, ans);
        keiro.pop_front();
    }
}


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(200, 0));
    dp.at(0).at(0) = 1;
    for(ll i = 1;i <= N; i++) {
        for(ll j = 0; j < 200; j++) {
            dp.at(i).at(j) += dp.at(i - 1).at(j);
            ll dist = A.at(i - 1) % 200;
            dp.at(i).at(j) += dp.at(i - 1).at((j - dist + 200) % 200);
        }
    }

     // 復元
    deque<ll> keiro;
    vector<deque<ll>> ans;
    for(ll i = 1; i < 200; i++) {
        if(dp.at(N).at(i) >= 2) {
            rec(dp, A, N, i, keiro, ans);
            cout << "Yes" << endl;
            cout << ans.at(0).size() << " ";
            for(const ll &b : ans.at(0)) {
                cout << b << " ";
            }
            cout << endl;
            cout << ans.at(1).size() << " ";
            for(const ll &c : ans.at(1)) {
                cout << c << " ";
            }
            cout << endl;
            return 0;
        }
    }

    if(dp.at(N).at(0) >= 3) {
        rec(dp, A, N, 0, keiro, ans);
        cout << "Yes" << endl;
        cout << ans.at(1).size() << " ";
        for(const ll &b : ans.at(1)) {
            cout << b << " ";
        }
        cout << endl;
        cout << ans.at(2).size() << " ";
        for(const ll &c : ans.at(2)) {
            cout << c << " ";
        }
        cout << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}