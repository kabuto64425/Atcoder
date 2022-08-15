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
    ll ans = 0;
    for(ll i = 0; i < 10; i++) {
        for(ll j = 0; j < 10; j++) {
            for(ll k = 0; k < 10; k++) {
                char first = (char)('0' + i);
                char second = (char)('0' + j);
                char third = (char)('0' + k);
                bool findFirst = false;
                bool findSecond = false;
                bool findThird = false;
                for(const char &c : S) {
                    if(findFirst and findSecond) {
                        if(c == third) {
                            findThird = true;
                        }
                    } else if(findFirst) {
                        if(c == second) {
                            findSecond = true;
                        }
                    } else {
                        if(c == first) {
                            findFirst = true;
                        }
                    }
                }
                if(findFirst and findSecond and findThird) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}