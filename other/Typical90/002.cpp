#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<string> vec;
    for(ll bit = 0; bit < (1 << N); bit++) {
        ll x = 0;
        string s;
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                x--;
                if(x < 0) {
                    break;
                }
                s += ")";
            } else {
                x++;
                s += "(";
            }
        }
        if(x != 0) {
            continue;
        }

        vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    for(const string &s : vec) {
        cout << s << endl;
    }
    return 0;
}