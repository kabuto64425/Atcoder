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
    string s;
    cin >> s;
    ll K;
    cin >> K;
    vector<string> vec;
    for(ll i = 0; i < (ll)s.length(); i++) {
        ll len = min(5LL, (ll)s.length() - i);
        for(ll j = 1; j <= len; j++) {
            string t = s.substr(i, j);
            vec.push_back(t);
        }
    }
    sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    cout << vec.at(K - 1) << endl;
    return 0;
}