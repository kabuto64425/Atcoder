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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll countR = 0;
    for(const char &c : S) {
        if(c == 'R') {
            countR++;
        }
    }
    ll countLR = 0;
    for(ll i = 0; i < countR; i++) {
        if(S.at(i) == 'R') {
            countLR++;
        }
    }
    cout << countR - countLR << endl;
    return 0;
}