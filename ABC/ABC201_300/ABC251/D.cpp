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
    ll W;
    cin >> W;
    vector<ll> ans;
    ll d = 1;
    for(ll i = 0; i < 3; i++) {
        for(ll j = 1; j <= 99; j++) {
            ans.push_back(j * d);
        }
        d *= 100;
    }
    ans.push_back(1000000);
    cout << ans.size() << endl;
    for(ll i = 0; i < (ll)ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}