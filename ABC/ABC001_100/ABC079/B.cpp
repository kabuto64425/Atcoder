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
    ll N;
    cin >> N;
    vector<ll> luca(100, 0);
    luca.at(0) = 2;
    luca.at(1) = 1;
    for(ll i = 2; i <= 86; i++) {
        luca.at(i) = luca.at(i - 1) + luca.at(i - 2);
    }
    cout << luca.at(N) << endl;
    return 0;
}