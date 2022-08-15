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
    ll A, B, K;
    cin >> A >> B >> K;
    ll j = 1;
    for(ll i = 100; i >= 1; i--) {
        if(A % i == 0 and B % i == 0) {
            if(j == K) {
                cout << i << endl;
                return 0;
            }
            j++;
        }
    }
    return 0;
}