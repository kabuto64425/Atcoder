#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    
    vector<ll> vec(10000001, 0);
    vec.at(0) = 0;
    vec.at(1) = 0;
    
    ll ans = 0;
    
    for(ll i = 2; i <= N; i++) {
        if(vec.at(i) >= 1) {
            continue;
        }
        for(ll j = 1; i * j <= N; j++) {
            vec.at(i * j)++;
            if(vec.at(i * j) == K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}