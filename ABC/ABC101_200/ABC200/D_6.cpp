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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<vector<vector<ll>>> dp(201, vector<vector<ll>>(200, vector<ll>(2)));
    dp.at(0).at(0).at(0) = 1;
    vector<pair<ll, ll>> pre[201][200][2];
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < 200; j++) {
            if(dp[i][j][0] > 0) {
                dp.at(i + 1).at(j).at(0) += dp.at(i).at(j).at(0);
                dp.at(i + 1).at(j).at(0) = min(dp.at(i + 1).at(j).at(0), 2LL);
                if(pre[i + 1][j][0].size() < 2) {
                    pre[i + 1][j][0].push_back({j, 0 * 2 + 0});
                }
                ll mo = (j + A.at(i)) % 200;
                dp.at(i + 1).at(mo).at(1) += dp.at(i).at(j).at(0);
                dp.at(i + 1).at(mo).at(1) = min(dp.at(i + 1).at(mo).at(1), 2LL);
                if(pre[i + 1][mo][1].size() < 2) {
                    pre[i + 1][mo][1].push_back({j, 0 * 2 + 1});
                }
            }
            
            if(dp[i][j][1] > 0) {
                dp.at(i + 1).at(j).at(1) += dp.at(i).at(j).at(1);
                dp.at(i + 1).at(j).at(1) = min(dp.at(i + 1).at(j).at(1), 2LL);
                if(pre[i + 1][j][1].size() < 2) {
                    pre[i + 1][j][1].push_back({j, 1 * 2 + 0});
                }
                
                ll mo = (j + A.at(i)) % 200;
                dp.at(i + 1).at(mo).at(1) += dp.at(i).at(j).at(1);
                dp.at(i + 1).at(mo).at(1) = min(dp.at(i + 1).at(mo).at(1), 2LL);
                if(pre[i + 1][mo][1].size() < 2) {
                    pre[i + 1][mo][1].push_back({j, 1 * 2 + 1});
                }
            }
        }
    }
    for(ll i = 0; i < 200; i++) {
        if(dp.at(N).at(i).at(1) >= 2) {
            cout << "Yes" << endl;
            vector<ll> ansB;
            ll mod = i;
            ll isSelected = 1;
            for(ll j = N; j >= 1; j--) {
                pair<ll, ll> tmp = pre[j][mod][isSelected].at(0);
                mod = tmp.first;
                isSelected = tmp.second / 2;
                if(tmp.second % 2) {
                    ansB.push_back(j);
                }
            }

            vector<ll> ansC;
            mod = i;
            isSelected = 1;
            for(ll j = N; j >= 1; j--) {
                pair<ll, ll> tmp = pre[j][mod][isSelected].back();
                mod = tmp.first;
                isSelected = tmp.second / 2;
                if(tmp.second % 2) {
                    ansC.push_back(j);
                }
            }

            reverse(ALL(ansB));
            reverse(ALL(ansC));

            cout << ansB.size() << " ";
            for(ll j = 0; j < ansB.size(); j++) {
                cout << ansB.at(j) << " ";
            }
            cout << endl;
            cout << ansC.size() << " ";
            for(ll j = 0; j < ansC.size(); j++) {
                cout << ansC.at(j) << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}