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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(string &s : S) {
        cin >> s;
    }
    ll odd = 0;
    ll even = 0;
    for(const string &s : S) {
        ll count = 0;
        for(const char c : s) {
            if(c == '1') {
                count++;
            }
        }
        if(count % 2 == 1) {
            odd++;
        } else {
            even++;
        }
    }
    cout << odd * even << endl;
    return 0;
}