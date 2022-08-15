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
    ll N = S.length();
    for(ll i = 1; i <= N; i++) {
        if(S.at(i - 1) != S.at(N - i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(ll i = 1; i <= (N - 1) / 2; i++) {
        if(S.at(i - 1) != S.at((N - 1) / 2 - i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(ll i = (N + 3) / 2; i <= N; i++) {
        if(S.at(i - 1) != S.at(N - i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}