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
    if(S.at(0) == S.at(1) and S.at(0) == S.at(2) and S.at(0) == S.at(3)) {
        cout << "Weak" << endl;
        return 0;
    }
    ll a = S.at(0) - '0';
    ll b = S.at(1) - '0';
    ll c = S.at(2) - '0';
    ll d = S.at(3) - '0';
    if((a + 1) % 10 == b and (b + 1) % 10 == c and (c + 1) % 10 == d) {
        cout << "Weak" << endl;
        return 0;
    }
    cout << "Strong" << endl;
    return 0;
}