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
    ll A;
    string B;
    cin >> A >> B;
    ll Bdash = 0;
    Bdash += B.at(0) - '0';
    Bdash *= 100;
    Bdash += (B.at(2) - '0') * 10 + (B.at(3) - '0');
    cout << A * Bdash / 100 << endl;
    return 0;
}