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
    string s;
    cin >> s;
    deque<char> Q1;
    for(char &elm : s) {
        if(elm == '0' or elm == '1') {
            Q1.push_back(elm);
        } else if (elm == 'B') {
            if(!Q1.empty()) {
                Q1.pop_back();
            }
        }
    }
    while(!Q1.empty()) {
        cout << Q1.front();
        Q1.pop_front();
    }
    cout << endl;
    return 0;
}