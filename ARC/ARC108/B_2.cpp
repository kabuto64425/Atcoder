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
    string s;
    cin >> s;
    stack<char> t;
    for(const char &elm : s) {
        t.push(elm);
        if(t.size() >= 3) {
            char third = t.top();
            t.pop();
            char second = t.top();
            t.pop();
            char first = t.top();
            t.pop();
            if(first != 'f' or second != 'o' or third != 'x') {
                t.push(first);
                t.push(second);
                t.push(third);
            }
        }
    }
    cout << t.size() << endl;
    return 0;
}