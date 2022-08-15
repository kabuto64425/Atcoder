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
    ll j = 1000000;
    ll ans = INF;
    for(ll i = 0; i <= 1000000; i++) {
        while(j >= 0 and i * i * i + i * i * j + i * j * j + j * j * j >= N) {
            ans = min(ans, i * i * i + i * i * j + i * j * j + j * j * j);
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}