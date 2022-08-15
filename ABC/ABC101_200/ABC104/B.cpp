#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string S;
    cin >> S;
    if(S.at(0) != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    ll N = S.length();
    ll countC = 0;
    for(ll i = 2; i <= N - 2; i++) {
        if(S.at(i) == 'C') {
            countC++;
        }
    }
    if(countC != 1) {
        cout << "WA" << endl;
        return 0;
    }
    ll countLowercase = 0;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) >= 'a' and S.at(i) <= 'z') {
            countLowercase++;
        }
    }
    if(countLowercase <= N - 3) {
        cout << "WA" << endl;
        return 0;
    }
    cout << "AC" << endl;
    return 0;
}