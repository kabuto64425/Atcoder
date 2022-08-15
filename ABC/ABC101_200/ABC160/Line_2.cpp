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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> k(N, 0);
    for(ll i = 1; i <= N - 1; i++) {
        for(ll j = i + 1; j <= N; j++) {
            ll d = min({j - i, abs(i - X) + abs(j - Y) + 1, abs(i - Y) + abs(j - XATTR_LIST_MAX) + 1});
            k[d]++;
        }
    }
    for(ll i = 1; i < N; i++) {
        cout << k[i] << endl;
    }
    return 0;
}