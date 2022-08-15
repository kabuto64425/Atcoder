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

ll func(ll n) {
    if(n % 2 == 0) {
        return n / 2;
    }
    return 3 * n + 1;
}

int main(){
    ll s;
    cin >> s;
    vector<bool> isAppeared(1000001, false);
    isAppeared.at(s) = true;
    ll a = s;
    ll m = 2;
    while(!isAppeared.at(func(a))) {
        a = func(a);
        isAppeared.at(a) = true;
        m++;
    }
    cout << m << endl;
    return 0;
}