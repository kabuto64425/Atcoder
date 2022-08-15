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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> vec;
    if(S.at(0) == '0') {
        vec.push_back(0);
    }
    ll con = 1;
    for(ll i = 1; i < N; i++) {
        if(S.at(i) == S.at(i - 1)) {
            con++;
        } else {
            vec.push_back(con);
            con = 1;
        }
    }
    vec.push_back(con);
    if(S.at(S.length() - 1) == '0') {
        vec.push_back(0);
    }
    vector<ll> sum(vec.size() + 1, 0);
    for(ll i = 1; i <= vec.size(); i++) {
        sum.at(i) = sum.at(i - 1) + vec.at(i - 1);
    }
    ll ans = 0;
    if(vec.size() < 2 * K + 1) {
        cout << sum.at(sum.size() - 1) << endl;
        return 0;
    }
    for(ll i = 2 * K + 1; i <= vec.size(); i += 2) {
        ans = max(ans, sum.at(i) - sum.at(i - (2 * K + 1)));
    }
    cout << ans << endl;
    return 0;
}