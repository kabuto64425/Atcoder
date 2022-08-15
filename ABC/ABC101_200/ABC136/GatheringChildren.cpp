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
    string S;
    cin >> S;
    vector<ll> vec(S.length(), 0);
    ll con = 0;
    for(ll i = 0; i < S.length(); i++) {
        if(S[i] == 'R') {
            con++;
        } else {
            vec[i - 1] += (con + 1) / 2;
            vec[i] += con / 2;
            con = 0;
        }
    }
    con = 0;
    for(ll i = S.length() - 1; i >= 0; i--) {
        if(S[i] == 'L') {
            con++;
        } else {
            vec[i + 1] += (con + 1) / 2;
            vec[i] += con / 2;
            con = 0;
        }
    }
    for(const ll &v : vec) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}