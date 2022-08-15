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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, D;
    cin >> N >> D;
    vector<mint> pow2table(2200000, 1);
    pow2table.at(0) = 1;
    for(ll i = 0; i < 2000000; i++) {
        pow2table.at(i + 1) = pow2table.at(i) * 2;
    }
    mint ans = 0;
    for(ll d = 0; d < N; d++) {
        mint current = 0;
        // 祖先が両端のうちのどちらかに存在するパターン
        if(d + D < N) {
            current += pow2table.at(D + 1);
        }
        if(D >= 2) {
            ll count = min(N - d - 1, D - 1) - max(D + d - N + 1, 1LL) + 1;
            if(count >= 0) {
                current += (pow2table.at(D - 1) * (mint)count);
            }
        }
        current *= pow2table.at(d);
        ans += current;
    }
    cout << ans.val() << endl;
    return 0;
}