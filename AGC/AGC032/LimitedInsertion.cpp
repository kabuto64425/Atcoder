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
    vector<ll> B(N);
    for(ll &b : B) {
        cin >> b;
    }
    stack<ll> s;
    while(N > 0) {
        ll findedIndex = -1;
        for(ll i = N - 1; i >= 0; i--) {
            if(i + 1 == B.at(i)) {
                s.push(i + 1);
                findedIndex = i;
                break;
            }
        }
        if(findedIndex != -1) {
            N--;
            B.erase(B.begin() + findedIndex);
        } else {
            cout << - 1 << endl;
            return 0;
        }
    }
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}