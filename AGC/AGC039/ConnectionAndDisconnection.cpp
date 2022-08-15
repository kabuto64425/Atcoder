#include <bits/stdc++.h>
using namespace std;
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
    ll K;
    cin >> K;
    ll count = 0;
    ll continuous = 1;
    ll firstContinuous = -1;
    for(ll i = 0; i < S.length() - 1; i++) {
        if(S[i] == S[i + 1]) {
            continuous++;
        } else {
            if(firstContinuous == -1) {
                firstContinuous = continuous;
            }
            count += continuous / 2;
            continuous = 1;
        }
    }
    ll lastContinuous = continuous;
    count += continuous / 2;
    if(S[S.length() - 1] == S[0]) {
        if(firstContinuous == -1) {
            cout << continuous * K / 2 << endl;
        } else {
            cout << firstContinuous / 2 + (count - firstContinuous / 2 - lastContinuous / 2) * K  + ((firstContinuous + lastContinuous) / 2) * (K - 1) + lastContinuous / 2 << endl;
        }
    } else {
        cout << count * K << endl;
    }
    return 0;
}