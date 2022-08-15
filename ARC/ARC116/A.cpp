#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = LLONG_MAX;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll T;
    cin >> T;
    vector<ll> testCase(T);
    for(ll &N : testCase) {
        cin >> N;
    }
    for(const ll &N : testCase) {
        if(N % 4 == 0) {
            cout << "Even" << endl;
        } else if(N % 2 == 0) {
            cout << "Same" << endl;
        } else {
            cout << "Odd" << endl;
        }
    }
    return 0;
}