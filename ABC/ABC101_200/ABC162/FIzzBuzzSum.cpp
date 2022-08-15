#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    ans += (1 + N) * N / 2;
    ans -= (3 + (N - N % 3)) * (N / 3) / 2;
    ans -= (5 + (N - N % 5)) * (N / 5) / 2;
    ans += (15 + (N - N % 15)) * (N / 15) / 2;
    cout << ans << endl;
    return 0;
}