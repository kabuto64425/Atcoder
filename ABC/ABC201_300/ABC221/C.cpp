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
    string N;
    cin >> N;

    vector<ll> v;
    for(ll i = 0; i < (ll) N.length(); i++) {
        v.push_back(N.at(i) - '0');
    }

    sort(ALL(v));

    ll ans = 0;

    do {
        for(ll i = 1; i <= (ll) N.length() - 1; i++) {
            if(v.at(0) == 0 or v.at(i) == 0) {
                continue;
            }
            ll a = 0;
            for(ll j = 0; j < i; j++) {
                a *= 10;
                a += v.at(j);
            }
            ll b = 0;
            for(ll j = i; j < (ll) N.length(); j++) {
                b *= 10;
                b += v.at(j);
            }
            ll c = a * b;
            ans = max(ans, c);
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}