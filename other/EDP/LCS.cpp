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

int main(){
    string s;
    string t;
    cin >> s;
    cin >> t;
    vector<vector<ll>> dp(s.length() + 1, vector<ll>(t.length() + 1));
    dp.at(0).at(0) = 0;
    for(ll i = 0; i <= s.length(); i++) {
        for(ll j = 0; j <= t.length(); j++) {
            if(i >= 1) {
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j));
            }
            if(j >= 1) {
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i).at(j - 1));
            }
            if(i >= 1 and j >= 1) {
                ll len = dp.at(i - 1).at(j - 1);
                if(s.at(i - 1) == t.at(j - 1)) {
                    len++;
                }
                dp.at(i).at(j) = max(dp.at(i).at(j), len);
            }
        }
    }

    string ans;

    ll len = dp.at(s.length()).at(t.length());
    ll i = s.length();
    ll j = t.length();
    while(len > 0) {
        if(s.at(i - 1) == t.at(j - 1)) {
            ans += s.at(i - 1);
            len--;
            i--;
            j--;
        } else if(dp.at(i).at(j) == dp.at(i - 1).at(j)) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}