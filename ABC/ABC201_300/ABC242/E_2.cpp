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
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll T;
    cin >> T;
    vector<ll> N(T);
    vector<string> S(T);
    for(ll i = 0; i < T; i++) {
        cin >> N.at(i);
        cin >> S.at(i);
    }

    for(ll t = 0; t < T; t++) {
        ll n = N.at(t);
        string s = S.at(t);
        ll l = (n + 1) / 2;
        mint ans = 0;
        for(ll i = 0; i < l; i++) {
            ans *= 26;
            ans += (ll)(s.at(i) - 'A');
        }
        ans++;
        string temp;
        for(ll i = 0; i < n; i++) {
            temp += s.at(min(i, n - i - 1));
        }
        if(temp > s) {
            ans--;
        }
        cout << ans.val() << endl;
    }
    return 0;
}