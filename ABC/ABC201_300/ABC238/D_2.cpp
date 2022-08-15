#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;

int main(){
    ll N;
    cin >> N;
    ll d = 1;
    mint ans = 0;
    while(N >= d * 10) {
        mint current = 1 + (d * 9);
        current *= d * 9;
        current /= 2;
        ans += current;
        d *= 10;
    }
    mint current = 1 + (N - (d - 1));
    current *= (N - (d - 1));
    current /= 2;
    ans += current;
    cout << ans.val() << endl;
    return 0;
}