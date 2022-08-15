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
    ll T;
    cin >> T;
    vector<ll> N2(T), N3(T), N4(T);
    for(ll i = 0; i < T; i++) {
        cin >> N2.at(i) >> N3.at(i) >> N4.at(i);
    }
    for(ll i = 0; i < T; i++) {
        ll a1 = min(N3.at(i) / 2, N4.at(i));
        N3.at(i) -= (a1 * 2);
        N4.at(i) -= a1;
        ll a2 = min(N2.at(i) / 2, N3.at(i) / 2);
        N2.at(i) -= (a2 * 2);
        N3.at(i) -= (a2 * 2);
        ll a3 = min(N2.at(i), N4.at(i) / 2);
        N2.at(i) -= a3;
        N4.at(i) -= (a3 * 2);
        ll a4 = min(N2.at(i) / 3, N4.at(i));
        N2.at(i) -= (a4 * 3);
        N4.at(i) -= a4;
        ll a5 = N2.at(i) / 5;
        cout << a1 + a2 + a3 + a4 + a5 << endl;
    }
    return 0;
}