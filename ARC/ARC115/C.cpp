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
    vector<ll> ans(N + 1);
    ans.at(1) = 1;
    for(ll i = 2; i <= N; i++) {
        ll current = 0;
        vector<ll> vec;
        for(ll j = 1; j * j <= N; j++) {
            if(i % j == 0) {
                current = max(current, ans.at(j));
                current = max(current, ans.at(i / j));
            }
        }
        ans.at(i) = current + 1;
    }
    for(ll i = 1; i <= N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}