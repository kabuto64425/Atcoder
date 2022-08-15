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
    ll N;
    cin >> N;
    vector<string> S(N);
    for(string &s : S) {
        cin >> s;
    }
    map<string,pair<bool, bool>> m;
    for(const string &s : S) {
        if(s.at(0) == '!') {
            m[s.substr(1, s.length() - 1)].first = true;
        } else {
            m[s].second = true;
        }
    }
    for (auto elm : m) {
        if(elm.second.first and elm.second.second) {
           cout << elm.first << endl;
           return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}