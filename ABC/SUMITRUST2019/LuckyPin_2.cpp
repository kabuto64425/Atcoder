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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = 0;
    for(ll i = 0; i <= 999; i++) {
        std::stringstream ss;
        ss << std::setw(3) << std::setfill('0') << i;
        string n = ss.str();
        ll finded = 0;
        for(ll j = 0; j < N; j++) {
            if(S.at(j) == n.at(finded)) {
                finded++;
                if(finded == 3) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}