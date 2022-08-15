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
    string S;
    cin >> S;
    ll N = S.length();
    for(ll i = N - 2; i >= 0; i -= 2) {
        bool flag = true;
        for(ll j = 1; j * 2 <= i; j++) {
            if(S.at(j - 1) != S.at(i / 2 + j - 1)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}