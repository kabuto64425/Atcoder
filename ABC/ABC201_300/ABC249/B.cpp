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
    string S;
    cin >> S;
    set<char> se;
    bool oomoji = false;
    bool komojo = false;
    for(char &c : S) {
        if(se.count(c)) {
            cout << "No" << endl;
            return 0;
        }
        se.insert(c);
        if(c >= 'A' and c <= 'Z') {
            oomoji = true;
        }
        if(c >= 'a' and c <= 'z') {
            komojo = true;
        }
    }
    if(oomoji and komojo) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}