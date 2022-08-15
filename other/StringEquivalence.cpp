#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

ll N;

void recur(vector<string> &vec, string s,ll index) {
    if(s.length() == N) {
        vec.push_back(s);
        return;
    }
    for(ll i = 0; i < index; i++) {
        recur(vec, s + (char)('a' + i), (i == (index - 1))? (index + 1) : index);
    }
}

signed main(){
    cin >> N;
    vector<string> vec;
    string s = "a";
    ll index = 2;
    recur(vec, s, index);
    sort(vec.begin(), vec.end());
    REP(i, vec.size()) {
        cout << vec.at(i) << endl;
    }
}