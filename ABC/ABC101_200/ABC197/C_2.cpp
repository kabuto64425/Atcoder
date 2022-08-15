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
    vector<ll> A(N);
    for(ll &a: A) {
        cin >> a;
    }
    ll ans = INF;
    for (ll tmp = 0; tmp < (1 << (N - 1)); tmp++) {
        bitset<20> s(tmp);
        ll current = 0;
        ll x = A.at(0);
        for(ll i = 1; i < N; i++) {
            if(s.test(i - 1)) {
                x = x | A.at(i);
            } else {
                current = current ^ x;
                x = A.at(i);
            }
        }
        current = current ^ x;
        ans = min(ans, current);
       
    }
    cout << ans << endl;
    return 0;
}