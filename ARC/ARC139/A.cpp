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
    vector<ll> d(42);
    d.at(0) = 1;
    for(ll i = 0; i < 41; i++) {
        d.at(i + 1) = d.at(i) * 2; 
    }

    ll N;
    cin >> N;
    vector<ll> T(N);
    for(ll i = 0; i < N ; i++) {
        cin >> T.at(i);
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        bitset<200> bs(ans);
        if(bs.test(T.at(i))) {
            ans += d.at(T.at(i) + 1);
        } else {
            ans += d.at(T.at(i));
        }

        bs = bitset<200>(ans);

        for(ll j = T.at(i) - 1; j >= 0; j--) {
            bs.reset(j);
        }
        ans = bs.to_ullong();
    }
    cout << ans << endl;
    return 0;
}