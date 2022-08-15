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
    ll A, B, C;
    cin >> A >> B >> C;
    ll countFive = 0;
    ll countSeven = 0;
    if(A == 5) {
        countFive++;
    }
    if(A == 7) {
        countSeven++;
    }
    if(B == 5) {
        countFive++;
    }
    if(B == 7) {
        countSeven++;
    }
    if(C == 5) {
        countFive++;
    }
    if(C == 7) {
        countSeven++;
    }
    if(countFive == 2 and countSeven == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}