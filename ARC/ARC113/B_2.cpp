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

ll pow_mod(ll x, ll n, ll size) {
    ll res = 1;
    while(n) {
        if(n % 2) {
            res *= x;
            res = res % size;
        }
        x *= x;
        x = x % size;
        n >>= 1;
    }
    return res;
}

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    vector<vector<ll>> cycles(10);
    for(ll i = 0; i < 10; i++) {
        ll x = i;
        cycles.at(i).push_back(x);
        while((x * i) % 10 != i) {
            x = (x * i) % 10;
            cycles.at(i).push_back(x);
        }
    }
    ll a = A % 10;
    ll size = cycles.at(a).size();
    ll bmod = B % size;
    ll mod = pow_mod(bmod, C, size);
    cout << cycles.at(a).at((mod + size - 1) % size) << endl;
    return 0;
}