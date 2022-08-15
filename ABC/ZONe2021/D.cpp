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
    string S;
    cin >> S;
    deque<char> deq;
    ll isReverse = false;
    for(char &c : S) {
        if(c == 'R') {
            isReverse = !isReverse;
        } else if(isReverse) {
            deq.push_front(c);
        } else {
            deq.push_back(c);
        }
    }

    deque<char> ans;
    while(!deq.empty()) {
        char c;
        if(isReverse) {
            c = deq.back();
            ans.push_back(c);
            deq.pop_back();
        } else {
            c = deq.front();
            ans.push_back(c);
            deq.pop_front();
        }

        if(ans.size() >= 2) {
            char c1 = ans.back();
            ans.pop_back();
            char c2 = ans.back();
            ans.pop_back();
            if(c1 != c2) {
                ans.push_back(c2);
                ans.push_back(c1);
            }
        }
    }

    while(!ans.empty()) {
        cout << ans.front();
        ans.pop_front();
    }

    cout << endl;
    return 0;
}