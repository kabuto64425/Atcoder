#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string S;
    cin >> S;
    ll N = S.length();
    vector<vector<mint>> dp(110000, vector<mint>(13, 0));
    dp.at(0).at(0) = 1;
    ll d = 1;
    reverse(ALL(S));
    for(ll i = 1; i <= N; i++) {
        if(S.at(i - 1) == '?') {
            for(ll j = 0; j < 10; j++) {
                for(ll k = 0; k < 13; k++) {
                    ll t = j * d + k;
                    t %= 13;
                    dp.at(i).at(t) += dp.at(i - 1).at(k);
                }
            }
        } else {
            ll j = S.at(i - 1) - '0';
            for(ll k = 0; k < 13; k++) {
                ll t = j * d + k;
                t %= 13;
                dp.at(i).at(t) += dp.at(i - 1).at(k);
            }
        }
        d *= 10;
        d %= 13;
    }
    cout << dp.at(N).at(5).val() << endl;
    return 0;
}