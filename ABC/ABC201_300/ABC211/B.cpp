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
    string S1, S2, S3, S4;
    cin >> S1 >> S2 >> S3 >> S4;
    map<string, ll> m;
    if(m.count(S1)) {
        cout << "No" << endl;
        return 0;
    }
    m[S1] = 1;
    if(m.count(S2)) {
        cout << "No" << endl;
        return 0;
    }
    m[S2] = 1;
    if(m.count(S3)) {
        cout << "No" << endl;
        return 0;
    }
    m[S3] = 1;
    if(m.count(S4)) {
        cout << "No" << endl;
        return 0;
    }
    m[S4] = 1;
    cout << "Yes" << endl;
    return 0;
}