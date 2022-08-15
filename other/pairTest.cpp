#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

void test(pair<ll, ll> p) {
    cout << &p << endl;
    test(p);
}

signed main(){
    pair<ll, ll> p;
    p.first = 1;
    p.second = 2;
    test(p);
    cout << &p << endl;
}