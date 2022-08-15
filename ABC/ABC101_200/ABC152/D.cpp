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
    vector<vector<ll>> mapping(10, vector<ll>(10));
    for(ll i = 1; i <= N; i++) {
        if(i % 10 == 0) {
            continue;
        }
        string s = to_string(i);
        ll top = (ll)(s.at(0) - '0');
        ll bottom = (ll)(s.at(s.length() - 1) - '0');
        mapping.at(top).at(bottom)++;
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        if(i % 10 == 0) {
            continue;
        }
        string s = to_string(i);
        ll top = (ll)(s.at(0) - '0');
        ll bottom = (ll)(s.at(s.length() - 1) - '0');
        ans += mapping.at(bottom).at(top);
    }
    cout << ans << endl;
    return 0;
}