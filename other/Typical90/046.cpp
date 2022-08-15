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
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    for(ll &a : A) {
        cin >> a;
    }
    for(ll &b : B) {
        cin >> b;
    }
    for(ll &c : C) {
        cin >> c;
    }

    vector<ll> cycleA(46, 0);
    vector<ll> cycleB(46, 0);
    vector<ll> cycleC(46, 0);

    for(const ll &a : A) {
        cycleA.at(a % 46)++;
    }
    for(const ll &b : B) {
        cycleB.at(b % 46)++;
    }
    for(const ll &c : C) {
        cycleC.at(c % 46)++;
    }

    ll ans = 0;
    for(ll a = 0; a < 46; a++) {
        for(ll b = 0; b < 46; b++) {
            for(ll c = 0; c < 46; c++) {
                if((a + b + c) % 46 == 0) {
                    ans += (cycleA.at(a) * cycleB.at(b) * cycleC.at(c));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}