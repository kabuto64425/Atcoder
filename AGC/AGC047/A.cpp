#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    for(string &s : S) {
        cin >> s;
    }
    vector<vector<ll>> vec(51, vector<ll>(51, 0));
    for(ll i = 0; i < N; i++) {
        string s = S.at(i);
        ll a = 0;
        ll j = 0;
        while(j < (ll)s.size() and s.at(j) != '.') {
            a *= 10;
            a += (s.at(j) - '0');
            j++;
        }
        for(ll k = 0; k < 9; k++) {
            a *= 10;
            if(k + j + 1 < (ll)s.size()) {
                a += (s.at(k + j + 1) - '0');
            }
        }
        ll count2 = 0;
        while(a % 2 == 0) {
            count2++;
            a /= 2;
        }
        ll count5 = 0;
        while(a % 5 == 0) {
            count5++;
            a /= 5;
        }
        vec.at(count2).at(count5)++;
    }
    ll ans = 0;
    for(ll i = 0; i <= 2599; i++) {
        for(ll j = i + 1; j <= 2600; j++) {
            ll p = i / 51;
            ll q = i % 51;
            ll r = j / 51;
            ll s = j % 51;
            if(p + r < 18 or q + s < 18) {
                continue;
            }
            ans += vec.at(p).at(q) * vec.at(r).at(s);
        }
    }
    for(ll i = 0; i <= 2600; i++) {
        ll p = i / 51;
        ll q = i % 51;
        if(p + p < 18 or q + q < 18) {
            continue;
        }
        ans += vec.at(p).at(q) * (vec.at(p).at(q) - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}