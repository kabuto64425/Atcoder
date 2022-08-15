#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(string &s : S) {
        cin >> s;
    }
    ll ans = 0;
    for(ll i = 1; i <= H - 2; i++) {
        for(ll j = 1; j <= W - 2; j++) {
            if(S.at(i).at(j) == '#') {
                if(S.at(i - 1).at(j) == '.' and S.at(i).at(j - 1) == '.') {
                ans++;
                }
                if(S.at(i - 1).at(j) == '.' and S.at(i).at(j + 1) == '.') {
                    ans++;
                }
                if(S.at(i + 1).at(j) == '.' and S.at(i).at(j - 1) == '.') {
                    ans++;
                }
                if(S.at(i + 1).at(j) == '.' and S.at(i).at(j + 1) == '.') {
                    ans++;
                }
            } else {
                if(S.at(i - 1).at(j) == '#' and S.at(i).at(j - 1) == '#') {
                ans++;
                }
                if(S.at(i - 1).at(j) == '#' and S.at(i).at(j + 1) == '#') {
                    ans++;
                }
                if(S.at(i + 1).at(j) == '#' and S.at(i).at(j - 1) == '#') {
                    ans++;
                }
                if(S.at(i + 1).at(j) == '#' and S.at(i).at(j + 1) == '#') {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}