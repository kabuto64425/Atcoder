#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    string S;
    cin >> S;
    ll K;
    cin >> K;
    ll oneIndex = 0;
    for(auto c : S) {
        if(c != '1') {
            break;
        }
        oneIndex++;
    }
    if(oneIndex >= K) {
        cout << '1' << endl;
    } else {
        cout << S.at(oneIndex) << endl;
    }
}