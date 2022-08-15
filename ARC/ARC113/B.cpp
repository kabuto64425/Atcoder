#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    ll a = A % 10;
    if(a == 0 or a == 1 or a == 5 and a == 6) {
        cout << a << endl;
        return 0;
    }
    ll m;
    if(a == 2 or a == 3 or a == 7 or a == 8) {
        m = 4;
    } else {
        m = 2;
    }

    if(m == 2) {
        if(B % 2 == 0) {
            cout << (a * a) % 10 << endl;
        } else {
            cout << a << endl;
        }
        return 0;
    }

    if(B % 4 == 0) {
        cout << (a * a * a * a) % 10 << endl;
    } else if(B % 4 == 1) {
        cout << a << endl;
    } else if(B % 4 == 2) {
        if(C >= 2) {
            cout << (a * a * a * a) % 10 << endl;
        } else {
            cout << (a * a) % 10 << endl;
        }
    } else {
        if(C % 2 == 0) {
            cout << a << endl;
        } else {
            cout << (a * a * a) % 10 << endl;
        }
    }

    return 0;
}