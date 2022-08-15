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
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    dsu d(12);
    d.merge(0, 2);
    d.merge(0, 4);
    d.merge(0, 6);
    d.merge(0, 7);
    d.merge(0, 9);
    d.merge(0, 11);
    d.merge(3, 5);
    d.merge(3, 8);
    d.merge(3, 10);
    if(d.same(x, y)) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}