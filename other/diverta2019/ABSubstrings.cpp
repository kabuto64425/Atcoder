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

ll countWord(const string &str, const string &word) {
  ll count = 0;
  for (string::size_type pos = 0; (pos = str.find(word, pos)) != string::npos; pos++) {
    ++count;
  }
  return count;
}

int main(){
    ll N;
    cin >> N;
    vector<string> s(N);
    for(string &elm : s) {
        cin >> elm;
    }
    ll ans = 0;
    ll lastA = 0;
    ll firstB = 0;
    ll lastAfirstB = 0;
    for(string &elm : s) {
        ans += countWord(elm, "AB");
        if(elm.back() =='A' and elm.at(0) == 'B') {
            lastAfirstB++;
        } else if(elm.back() =='A') {
            lastA++;
        } else if(elm.at(0) == 'B') {
            firstB++;
        }
    }
    if(lastAfirstB > 0) {
        if(lastA + firstB > 0) {
            ans += min(lastA, firstB) + lastAfirstB;
        } else {
            ans += lastAfirstB - 1;
        }
    } else {
        ans += min(lastA, firstB);
    }
    cout << ans << endl;
    return 0;
}