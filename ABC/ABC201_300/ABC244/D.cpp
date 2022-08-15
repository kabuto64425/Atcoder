#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    char S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    char T1, T2, T3;
    cin >> T1 >> T2 >> T3;
    ll diff = 0;
    if(S1 != T1) {
        diff++;
    }
    if(S2 != T2) {
        diff++;
    }
    if(S3 != T3) {
        diff++;
    }
    if(diff == 2) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}