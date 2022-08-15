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
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    set<string> s;
    if(S1 != "ABC" and S2 != "ABC" and S3 != "ABC") {
        cout << "ABC" << endl;
        return 0;
    }
    if(S1 != "ARC" and S2 != "ARC" and S3 != "ARC") {
        cout << "ARC" << endl;
        return 0;
    }
    if(S1 != "AGC" and S2 != "AGC" and S3 != "AGC") {
        cout << "AGC" << endl;
        return 0;
    }
    if(S1 != "AHC" and S2 != "AHC" and S3 != "AHC") {
        cout << "AHC" << endl;
        return 0;
    }
    return 0;
}