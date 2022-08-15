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
    string S;
    cin >> S;
    for(ll i = 1; i <= S.length(); i++) {
        if(i % 2 == 1) {
            if(S.at(i - 1) != 'R' and S.at(i - 1) != 'U' and S.at(i - 1) != 'D') {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if(S.at(i - 1) != 'L' and S.at(i - 1) != 'U' and S.at(i - 1) != 'D') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}