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
    string S;
    cin >> S;
    ll K;
    cin >> K;
    vector<char> v;
    for(char &c : S) {
        v.push_back(c);
    }
    sort(v.begin(), v.end());

    vector<string> v2;

    do {
        string str = "";
        for(char &c : v) {
            str += c;
        }
        v2.push_back(str);
    } while (next_permutation(v.begin(), v.end()));

    sort(v2.begin(), v2.end());
    cout << v2.at(K - 1) << endl;
    return 0;
}