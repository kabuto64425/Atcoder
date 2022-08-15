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
    string S, T;
    cin >> S >> T;
    for(ll i = S.length() - 1; i >= T.length() - 1; i--) {
        bool flag = true;
        for(ll j = T.length() - 1; j >= 0; j--) {
            ll k = T.length() - j - 1;
            if(S[i - k] == '?') {
                continue;
            }
            if(S[i - k] != T[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            for(ll j = 0; j < S.length(); j++) {
                if(S[j] == '?') {
                    if(j >= i - T.length() + 1 and j <= i) {
                        cout << T[j - (i - T.length() + 1)];
                    } else {
                        cout << 'a';
                    }
                } else {
                    cout << S[j];
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
    return 0;
}