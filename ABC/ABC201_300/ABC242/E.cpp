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
    for(ll i = 0; i < T; i++) {
        ll d = (N.at(i) + 1) / 2;
        string Si = S.at(i);
        mint ans = 0;
        for(ll j = 0; j < d; j++) {
            ans *= 26;
            ans += (Si.at(j) - 'A');
        }
        ans++;
        string Sx;
        for(ll j = 0; j < N.at(i); j++) {
            Sx += Si.at(min(j, N.at(i) - j - 1));
        }
        if(Sx > Si) {
            ans--;
        }
        cout << ans.val() << endl;
    }
    return 0;
}