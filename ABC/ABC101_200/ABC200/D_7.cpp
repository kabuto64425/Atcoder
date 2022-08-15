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

void rec(const vector<vector<long long>> &dp, const vector<ll> &a, int i, int j, deque<int> &keiro, vector<deque<int>> &ans) {
    if (i == 0) {
        if (j == 0) {
            ans.push_back(keiro);
        }
        return;
    }
    if(ans.size() >= 3) {
        return;
    }

    // 上へ遡る (dp[i-1][j] == 0) だったら無視)
    if (dp[i-1][j]) {
        rec(dp, a, i-1, j, keiro, ans);
    }
    // 左上へ遡る (dp[i-1][m] == 0 だったら無視)
    ll m = (j - (a[i-1] % 200) + 200) % 200;
    if (dp[i-1][m]) {
        keiro.push_front(i);
        rec(dp, a, i-1, m, keiro, ans);
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
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j < 200; j++) {
            dp.at(i).at(j) += dp.at(i - 1).at(j);
            dp.at(i).at(j) = min(dp.at(i).at(j), 3LL);
            dp.at(i).at((j + A.at(i - 1)) % 200) += dp.at(i - 1).at(j);
            dp.at(i).at((j + A.at(i - 1)) % 200) = min(dp.at(i).at((j + A.at(i - 1)) % 200), 3LL);
        }
    }

    for(ll i = 0; i < 200; i++) {
        if(i == 0) {
            if(dp.at(N).at(i) >= 3) {
                cout << "Yes" << endl;

                // 復元
                deque<int> keiro;
                vector<deque<int>> ans;
                rec(dp, A, N, i, keiro, ans);

                cout << ans.at(1).size() << " ";
                while(!ans.at(1).empty()) {
                    cout << ans.at(1).front() << " ";
                    ans.at(1).pop_front();
                }
                cout << endl;
                cout << ans.at(2).size() << " ";
                while(!ans.at(2).empty()) {
                    cout << ans.at(2).front() << " ";
                    ans.at(2).pop_front();
                }
                cout << endl;
                return 0;
            }
        } else {
            if(dp.at(N).at(i) >= 2) {
                cout << "Yes" << endl;

                // 復元
                deque<int> keiro;
                vector<deque<int>> ans;
                rec(dp, A, N, i, keiro, ans);

                cout << ans.at(0).size() << " ";
                while(!ans.at(0).empty()) {
                    cout << ans.at(0).front() << " ";
                    ans.at(0).pop_front();
                }
                cout << endl;
                cout << ans.at(1).size() << " ";
                while(!ans.at(1).empty()) {
                    cout << ans.at(1).front() << " ";
                    ans.at(1).pop_front();
                }
                cout << endl;

                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}