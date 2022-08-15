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
    ll R = 0;
    ll G = 0;
    ll B = 0;
    for(const char &c : S) {
        if(c == 'R') {
            R++;
        } else if(c == 'G') {
            G++;
        } else if(c == 'B') {
            B++;
        }
    }
    ll ans = R * G * B;
    for(ll i = 0; i <= N - 3; i++) {
        for(ll j = i + 1; j <= N - 2; j++) {
            ll k = 2 * j - i;
            if(k >= N) {
                continue;
            }
            if(S.at(i) == S.at(j)) {
                continue;
            }
            if(S.at(i) == S.at(k)) {
                continue;
            }
            if(S.at(j) == S.at(k)) {
                continue;
            }
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}