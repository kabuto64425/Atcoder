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
    string S;
    cin >> S;
    ll N = S.length();
    vector<ll> v(N);
    for(ll i = 0; i < N; i++) {
        v.at(i) = (ll)(S.at(i) - '0');
    }
    ll ans = 0;
    for (ll bit = 0; bit < (1 << (N - 1)); bit++) {
        bitset<20> s(bit);
        ll current = v.at(0);
        for(ll i = 0; i < N - 1; i++) {
            if(s.test(i)) {
                current *= 10;
                current += v.at(i + 1);
            } else {
                ans += current;
                current = v.at(i + 1);
            }
        }
        ans += current;
    }
    cout << ans << endl;
    return 0;
}