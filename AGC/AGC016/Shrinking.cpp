#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string s;
    cin >> s;
    ll ans = INF;
    for(char c = 'a'; c <= 'z'; c++) {
        ll loop = 0;
        string convertedString = s;
        while(convertedString.find_first_not_of(c) != string::npos) {
            string generatingString;
            for(ll i = 1; i < convertedString.length(); i++) {
                if(convertedString.at(i) == c) {
                    generatingString += convertedString.at(i);
                } else {
                    generatingString += convertedString.at(i - 1);
                }
            }
            convertedString = generatingString;
            loop++;
        }
        ans = min(ans, loop);
    }
    cout << ans << endl;
    return 0;
}