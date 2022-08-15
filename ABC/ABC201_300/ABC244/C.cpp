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
    vector<ll> v(2 * N + 2);
    while(true) {
        for(ll i = 1; i <= 2 * N + 1; i++) {
            if(v.at(i) == 0) {
                v.at(i) = 1;
                cout << i << endl;
                break;
            }
        }
        ll x;
        cin >> x;
        if(x == 0) {
            return 0;
        }
        v.at(x) = 1;
    }
    return 0;
}