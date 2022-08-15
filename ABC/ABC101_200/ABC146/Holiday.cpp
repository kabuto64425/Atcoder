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
    vector<string> day(7);
    day.at(0) = "SAT";
    day.at(1) = "FRI";
    day.at(2) = "THU";
    day.at(3) = "WED";
    day.at(4) = "TUE";
    day.at(5) = "MON";
    day.at(6) = "SUN";
    for(ll i = 0 ; i < 7; i++) {
        if(day.at(i) == S) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}